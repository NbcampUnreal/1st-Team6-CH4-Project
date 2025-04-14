#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "YJ_MapSelectButtonWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMapSelectButtonClickedDelegate, int32, MapIndex);
/**
 * 
 */
UCLASS()
class THEFIGHTERS_API UYJ_MapSelectButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	virtual void NativeConstruct() override;

public:

	UFUNCTION(BlueprintCallable, Category = "YJMapSelectButtonWidget")
	void SetActiveHighlight(bool bShouldActivate);

public:

	UPROPERTY(BlueprintAssignable, Category = "YJMapSelectButtonWidget")
	FOnMapSelectButtonClickedDelegate OnMapSelectButtonClickedDelegate;

private:

	UFUNCTION()
	void OnMapSelectButtonClicked();

private:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> HighLight;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> MapText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess), Category = "YJMapSelectButtonWidget")
	int32 MapIndex = 0;
};
