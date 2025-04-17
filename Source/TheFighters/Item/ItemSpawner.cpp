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

    // ��Ʈ ������Ʈ ���� (�̵� �����ϵ��� SceneComponent ���)
    USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    RootComponent = SceneComponent;

    // �ʱ�ȭ
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

    StopSpawning(); // ���� Ÿ�̸� ����

    float NextSpawnTime;
    GetRandomSpawnTime(NextSpawnTime);

    GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AItemSpawner::SpawnItem, NextSpawnTime, false);
}

void AItemSpawner::StopSpawning()
{
    if (!HasAuthority()) return;

    GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
}
// SpawnItem �Լ� ����
void AItemSpawner::SpawnItem()
{
    if (!HasAuthority()) return;

    // ���� �������� ���� �����ϴ��� Ȯ��
    if (CurrentSpawnedItem && IsValid(CurrentSpawnedItem))
    {
        // �������� ���� �����ϸ� �ٽ� Ÿ�̸� ���� (���߿� �ٽ� üũ)
        float NextCheckTime = 2.0f; // 2�� �Ŀ� �ٽ� Ȯ��
        GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AItemSpawner::SpawnItem, NextCheckTime, false);
        return;
    }

    Server_SpawnItem();
}

void AItemSpawner::Server_SpawnItem_Implementation()
{
    if (SpawnableItems.Num() == 0) return;

    // ���� �������� �����ϴ��� �ѹ� �� Ȯ��
    if (CurrentSpawnedItem && IsValid(CurrentSpawnedItem))
    {
        // �������� ���� �����ϸ� ���߿� �ٽ� üũ
        float NextCheckTime = 2.0f;
        GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AItemSpawner::SpawnItem, NextCheckTime, false);
        return;
    }

    // ���� ������ Ŭ���� ����
    int32 RandomIndex = FMath::RandRange(0, SpawnableItems.Num() - 1);
    TSubclassOf<AItemBase> ItemClass = SpawnableItems[RandomIndex];

    if (ItemClass)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        FVector SpawnLocation = GetSpawnLocation();
        FRotator SpawnRotation = GetActorRotation();

        // ������ ���� �� ���� ����
        CurrentSpawnedItem = GetWorld()->SpawnActor<AItemBase>(ItemClass, SpawnLocation, SpawnRotation, SpawnParams);

        // ������ �Ҹ� �̺�Ʈ ���� �� ������ ����
        if (CurrentSpawnedItem)
        {
            CurrentSpawnedItem->OnDestroyed.AddDynamic(this, &AItemSpawner::OnItemDestroyed);
            CurrentSpawnedItem->SetSpawner(this);
        }
    }
}

// ������ ���� �̺�Ʈ �ڵ鷯 �߰�
void AItemSpawner::OnItemDestroyed(AActor* DestroyedActor)
{
    if (DestroyedActor == CurrentSpawnedItem)
    {
        CurrentSpawnedItem = nullptr;

        // �������� ���ŵǾ����Ƿ� �� ������ ���� ���� ����
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