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


public:


	UFUNCTION(Exec)
	void TestCPUMatch();
	
};
