#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "YJ_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class THEFIGHTERS_API AYJ_GameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	virtual void InitGameState() override;

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "YJCharacter")
	void OnInitGameState();

public:


	UFUNCTION(Exec)
	void TestCPUMatch();

	UFUNCTION(Exec)
	void SwitchTeamMode();
};
