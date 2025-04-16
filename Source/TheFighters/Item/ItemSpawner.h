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

    // 현재 생성된 아이템 추적용 변수 추가
    UPROPERTY()
    AItemBase* CurrentSpawnedItem;

    // 아이템 제거 이벤트 핸들러
    UFUNCTION()
    void OnItemDestroyed(AActor* DestroyedActor);

    UFUNCTION()
    void SpawnItem();

    UFUNCTION(Server, Reliable, WithValidation)
    void Server_SpawnItem();

    void GetRandomSpawnTime(float& OutTime);

    FTimerHandle SpawnTimerHandle;

    // 스폰 위치 오프셋 (루트 컴포넌트 기준)
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

    // 스폰 위치를 월드 좌표로 반환
    UFUNCTION(BlueprintCallable, Category = "Item Spawner")
    FVector GetSpawnLocation() const;
};