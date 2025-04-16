#include "Character/YJ_PlayerController.h"

void AYJ_PlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	PostInitComp();
}

void AYJ_PlayerController::PostNetInit()
{
	Super::PostNetInit();

	OnPostNetInit();
}
