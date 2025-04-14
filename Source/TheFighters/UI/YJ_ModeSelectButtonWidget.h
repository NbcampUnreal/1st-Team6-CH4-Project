#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "YJ_ModeSelectButtonWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnModeSelectButtonClickedDelegate);
/**
 * 
 */
UCLASS()
class THEFIGHTERS_API UYJ_ModeSelectButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	

protected:

	virtual void NativeConstruct() override;

public:


	UFUNCTION(BlueprintCallable, Category = "YJModeSelectButtonWidget")
	void ChangeModeText(bool bShouldChangeToCPUMode);

public:

	UPROPERTY(BlueprintAssignable, Category = "YJModeSelectButtonWidget")
	FOnModeSelectButtonClickedDelegate OnModeSelectButtonClickedDelegate;

private:

	UFUNCTION()
	void OnButtonClicked();

private:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class URichTextBlock> ButtonText;
};
