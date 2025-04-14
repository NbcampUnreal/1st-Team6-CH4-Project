#include "Item/ItemBase.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

AItemBase::AItemBase()
{
    PrimaryActorTick.bCanEverTick = true;
    bReplicates = true;

    // Root Scene
    RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
    RootComponent = RootScene;

    // Collision
    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    CollisionComponent->SetupAttachment(RootScene);
    CollisionComponent->InitSphereRadius(30.0f);
    CollisionComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

    // Mesh
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(CollisionComponent);
    MeshComponent->SetRelativeLocation(FVector::ZeroVector);
    MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    MeshComponent->SetWorldScale3D(FVector(0.5f));
    MeshComponent->SetMaterial(0, nullptr); // 머티리얼 제거
}

void AItemBase::BeginPlay()
{
    Super::BeginPlay();
}

void AItemBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 모든 아이템 회전 (Yaw 기준)
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += 60.0f * DeltaTime;
    SetActorRotation(NewRotation);
}

