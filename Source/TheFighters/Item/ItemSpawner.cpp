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

    // 초기화
    CurrentSpawnedItem = nullptr;
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
// SpawnItem 함수 수정
void AItemSpawner::SpawnItem()
{
    if (!HasAuthority()) return;

    // 현재 아이템이 아직 존재하는지 확인
    if (CurrentSpawnedItem && IsValid(CurrentSpawnedItem))
    {
        // 아이템이 아직 존재하면 다시 타이머 설정 (나중에 다시 체크)
        float NextCheckTime = 2.0f; // 2초 후에 다시 확인
        GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AItemSpawner::SpawnItem, NextCheckTime, false);
        return;
    }

    Server_SpawnItem();
}

void AItemSpawner::Server_SpawnItem_Implementation()
{
    if (SpawnableItems.Num() == 0) return;

    // 현재 아이템이 존재하는지 한번 더 확인
    if (CurrentSpawnedItem && IsValid(CurrentSpawnedItem))
    {
        // 아이템이 아직 존재하면 나중에 다시 체크
        float NextCheckTime = 2.0f;
        GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AItemSpawner::SpawnItem, NextCheckTime, false);
        return;
    }

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

        // 아이템 생성 및 참조 저장
        CurrentSpawnedItem = GetWorld()->SpawnActor<AItemBase>(ItemClass, SpawnLocation, SpawnRotation, SpawnParams);

        // 아이템 소멸 이벤트 구독 및 스포너 설정
        if (CurrentSpawnedItem)
        {
            CurrentSpawnedItem->OnDestroyed.AddDynamic(this, &AItemSpawner::OnItemDestroyed);
            CurrentSpawnedItem->SetSpawner(this);
        }
    }
}

// 아이템 제거 이벤트 핸들러 추가
void AItemSpawner::OnItemDestroyed(AActor* DestroyedActor)
{
    if (DestroyedActor == CurrentSpawnedItem)
    {
        CurrentSpawnedItem = nullptr;

        // 아이템이 제거되었으므로 새 아이템 생성 일정 설정
        float NextSpawnTime;
        GetRandomSpawnTime(NextSpawnTime);
        GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AItemSpawner::SpawnItem, NextSpawnTime, false);
    }
}

void AItemSpawner::GetRandomSpawnTime(float& OutTime)
{
    OutTime = FMath::FRandRange(MinSpawnTime, MaxSpawnTime);
}

FVector AItemSpawner::GetSpawnLocation() const
{
    return GetActorLocation() + GetActorRotation().RotateVector(SpawnOffset);
}

bool AItemSpawner::Server_SpawnItem_Validate()
{
    return true;
}