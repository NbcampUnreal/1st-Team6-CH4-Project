#include "Item/ItemBase.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Item/ItemSpawner.h"

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
    CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OnOverlapBegin);

    // Mesh
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(CollisionComponent);
    MeshComponent->SetRelativeLocation(FVector::ZeroVector);
    MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    MeshComponent->SetWorldScale3D(FVector(0.5f));
    MeshComponent->SetMaterial(0, nullptr);

    // �ʱ�ȭ
    SpawnerOwner = nullptr;
}

void AItemBase::BeginPlay()
{
    Super::BeginPlay();
}

void AItemBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // ��� ������ ȸ�� (Yaw ����)
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += 60.0f * DeltaTime;
    SetActorRotation(NewRotation);
}

void AItemBase::SetSpawner(AItemSpawner* Spawner)
{
    SpawnerOwner = Spawner;
}

void AItemBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    // �������Ʈ���� ó���� �����̹Ƿ� ���⼭�� �������� ����
    // ���߿� �ʿ��ϸ� ���⿡ ���� �߰�
}

