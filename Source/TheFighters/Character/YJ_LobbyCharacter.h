#pragma once

#include "CoreMinimal.h"
#include "Character/YJ_CharacterBase.h"

#include "YJ_LobbyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class THEFIGHTERS_API AYJ_LobbyCharacter : public AYJ_CharacterBase
{
	GENERATED_BODY()
	
protected:

	AYJ_LobbyCharacter();


public:

	UFUNCTION(BlueprintCallable, Category = "YJLobbyCharacter")
	void ActivateMesh(int32 MeshIndex);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "YJLobbyCharacter")
	TArray<TObjectPtr<USkeletalMeshComponent>> VisibleCharacterMesheCompList;

private:

	const int32 MESH_COUNT = 5;
};
