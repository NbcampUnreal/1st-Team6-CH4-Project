#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

class AItemSpawner;

UCLASS(Abstract)
class THEFIGHTERS_API AItemBase : public AActor
{
    GENERATED_BODY()

public:
    AItemBase();

    virtual void Tick(float DeltaTime) override;

    // 스포너 설정 함수
    void SetSpawner(AItemSpawner* Spawner);

protected:
    virtual void BeginPlay() override;

protected:
    UPROPERTY()
    AItemSpawner* SpawnerOwner;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
    class USceneComponent* RootScene;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
    class USphereComponent* CollisionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
    class UStaticMeshComponent* MeshComponent;
};