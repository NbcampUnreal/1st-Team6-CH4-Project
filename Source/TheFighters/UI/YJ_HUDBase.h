#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "YJ_HUDBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHudPostNetInitDelegate);
/**
 * 
 */
UCLASS()
class THEFIGHTERS_API AYJ_HUDBase : public AHUD
{
	GENERATED_BODY()
	
protected:

	virtual void PostNetInit() override;

public:

	UPROPERTY(BlueprintAssignable, Category = "YJHUDBase")
	FOnHudPostNetInitDelegate OnHudPostNetInitDelegate;
};
