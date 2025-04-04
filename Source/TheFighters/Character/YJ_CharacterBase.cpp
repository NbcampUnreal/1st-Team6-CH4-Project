


#include "Character/YJ_CharacterBase.h"

// Sets default values
AYJ_CharacterBase::AYJ_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AYJ_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AYJ_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AYJ_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

