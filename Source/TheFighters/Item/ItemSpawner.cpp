#include "Item/ItemSpawner.h"
#include "Item/ItemBase.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"

AItemSpawner::AItemSpawner()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;

    // 루트 컴포넌트 생성 (이동 가능하도록 SceneComponent 사용)
    USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    RootComponent = SceneComponent;
}

void AItemSpawner::BeginPlay()
{
    Super::BeginPlay();

    if (bAutoStart && HasAuthority())
    {
        StartSpawning();
    }
}

void AItemSpawner::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    StopSpawning();
    Super::EndPlay(EndPlayReason);
}

void AItemSpawner::StartSpawning()
{
    if (!HasAuthority()) return;

    StopSpawning(); // 기존 타이머 제거

    float NextSpawnTime;
    GetRandomSpawnTime(NextSpawnTime);

    GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AItemSpawner::SpawnItem, NextSpawnTime, false);
}

void AItemSpawner::StopSpawning()
{
    if (!HasAuthority()) return;

    GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
}

void AItemSpawner::SpawnItem()
{
    if (!HasAuthority()) return;

    Server_SpawnItem();
}

bool AItemSpawner::Server_SpawnItem_Validate()
{
    return true;
}

void AItemSpawner::Server_SpawnItem_Implementation()
{
    if (SpawnableItems.Num() == 0) return;

    // 랜덤 아이템 클래스 선택
    int32 RandomIndex = FMath::RandRange(0, SpawnableItems.Num() - 1);
    TSubclassOf<AItemBase> ItemClass = SpawnableItems[RandomIndex];

    if (ItemClass)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        FVector SpawnLocation = GetSpawnLocation();
        FRotator SpawnRotation = GetActorRotation();

        GetWorld()->SpawnActor<AItemBase>(ItemClass, SpawnLocation, SpawnRotation, SpawnParams);
    }

    // 다음 스폰 예약
    float NextSpawnTime;
    GetRandomSpawnTime(NextSpawnTime);
    GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AItemSpawner::SpawnItem, NextSpawnTime, false);
}

void AItemSpawner::GetRandomSpawnTime(float& OutTime)
{
    OutTime = FMath::FRandRange(MinSpawnTime, MaxSpawnTime);
}

FVector AItemSpawner::GetSpawnLocation() const
{
    return GetActorLocation() + GetActorRotation().RotateVector(SpawnOffset);
}