// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemSpawner.generated.h"

class AItemBase;

UCLASS()
class THEFIGHTERS_API AItemSpawner : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AItemSpawner();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

    // ���� ������ ������ ������ ���� �߰�
    UPROPERTY()
    AItemBase* CurrentSpawnedItem;

    // ������ ���� �̺�Ʈ �ڵ鷯
    UFUNCTION()
    void OnItemDestroyed(AActor* DestroyedActor);

    UFUNCTION()
    void SpawnItem();

    UFUNCTION(Server, Reliable, WithValidation)
    void Server_SpawnItem();

    void GetRandomSpawnTime(float& OutTime);

    FTimerHandle SpawnTimerHandle;

    // ���� ��ġ ������ (��Ʈ ������Ʈ ����)
    UPROPERTY(EditAnywhere, Category = "Item Spawner")
    FVector SpawnOffset = FVector::ZeroVector;

public:
    UPROPERTY(EditAnywhere, Category = "Item Spawner")
    TArray<TSubclassOf<AItemBase>> SpawnableItems;

    UPROPERTY(EditAnywhere, Category = "Item Spawner", meta = (ClampMin = 0.1))
    float MinSpawnTime = 5.0f;

    UPROPERTY(EditAnywhere, Category = "Item Spawner", meta = (ClampMin = 0.1))
    float MaxSpawnTime = 15.0f;

    UPROPERTY(EditAnywhere, Category = "Item Spawner")
    bool bAutoStart = true;

    UFUNCTION(BlueprintCallable, Category = "Item Spawner")
    void StartSpawning();

    UFUNCTION(BlueprintCallable, Category = "Item Spawner")
    void StopSpawning();

    // ���� ��ġ�� ���� ��ǥ�� ��ȯ
    UFUNCTION(BlueprintCallable, Category = "Item Spawner")
    FVector GetSpawnLocation() const;
};