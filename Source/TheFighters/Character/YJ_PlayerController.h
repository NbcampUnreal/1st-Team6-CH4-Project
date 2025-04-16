#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "YJ_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class THEFIGHTERS_API AYJ_PlayerController : public APlayerController
{
	GENERATED_BODY()
	

protected:

	virtual void PostInitializeComponents() override;
	virtual void PostNetInit() override;
	

	UFUNCTION(BlueprintImplementableEvent, Category = "YJPlayerController")
	void PostInitComp();

	UFUNCTION(BlueprintImplementableEvent, Category = "YJPlayerController")
	void OnPostNetInit();
};
