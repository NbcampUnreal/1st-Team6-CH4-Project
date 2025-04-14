#include "Character/YJ_LobbyCharacter.h"

AYJ_LobbyCharacter::AYJ_LobbyCharacter()
{

}

void AYJ_LobbyCharacter::ActivateMesh(int32 MeshIndex)
{
	int32 Index = FMath::Clamp(MeshIndex, 0, MESH_COUNT - 1);
	
	for (int i = 0; i < MESH_COUNT; ++i)
	{
		if (i == Index)
		{
			VisibleCharacterMesheCompList[i]->SetVisibility(true, true);

			VisibleCharacterMesheCompList[i]->SetHiddenInGame(false);       // °ÔÀÓ Áß ¼û±è ÇØÁ¦
			VisibleCharacterMesheCompList[i]->MarkRenderStateDirty();

			UE_LOG(LogTemp, Error, TEXT("MEsh Index : %d"), i);
		}
		else
		{
			VisibleCharacterMesheCompList[i]->SetVisibility(false, true);
			VisibleCharacterMesheCompList[i]->SetHiddenInGame(true);       // °ÔÀÓ Áß ¼û±è ÇØÁ¦
			VisibleCharacterMesheCompList[i]->MarkRenderStateDirty();
		}
	}
}
