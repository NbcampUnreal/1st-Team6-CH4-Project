#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "YJ_ReadyAndStartButtonWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReadyAndStartButtonClickedDelegate);
/**
 * 
 */
UCLASS()
class THEFIGHTERS_API UYJ_ReadyAndStartButtonWidget : public UUserWidget
{
	GENERATED_BODY()


protected:

	virtual void NativeConstruct() override;

public:

	UPROPERTY(BlueprintAssignable, Category = "YJReadyAndStartButtonWidget")
	FOnReadyAndStartButtonClickedDelegate OnReadyAndStartButtonClickedDelegate;

private:

	UFUNCTION()
	void OnButtonClicked();

private:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class URichTextBlock> ButtonText;
};
