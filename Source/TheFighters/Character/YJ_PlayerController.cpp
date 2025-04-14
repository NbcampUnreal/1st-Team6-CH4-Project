#include "Character/YJ_PlayerController.h"

void AYJ_PlayerController::PostNetInit()
{
	Super::PostNetInit();

	OnPostNetInit();
}