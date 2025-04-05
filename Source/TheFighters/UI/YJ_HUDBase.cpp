#include "UI/YJ_HUDBase.h"

void AYJ_HUDBase::PostNetInit()
{
	Super::PostNetInit();

	OnHudPostNetInitDelegate.Broadcast();
}
