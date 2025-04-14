#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "YJ_EnumContainer.h"

#include "YJ_CharacterSelectButtonWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterSelectButtonClickedDelegate, int32, CharacterIndex);

/**
 * 
 */
UCLASS()
class THEFIGHTERS_API UYJ_CharacterSelectButtonWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativeConstruct() override;

public:

	UFUNCTION(BlueprintCallable, Category = "YJCharacterSelectButtonWidget")
	void SetActivePlayerBorder(int32 PlayerIndex, bool bShouldActivate);

	UFUNCTION(BlueprintCallable, Category = "YJCharacterSelectButtonWidget")
	void SetNameText(const FString& NewNameText);

public:

	UPROPERTY(BlueprintAssignable, Category = "YJCharacterSelectButtonWidget")
	FOnCharacterSelectButtonClickedDelegate OnCharacterSelectButtonClickedDelegate;

private:

	UFUNCTION()
	void OnCharacterSelectButtonClicked();

private:

	UPROPERTY()
	TArray<TObjectPtr<class UImage>> PlayerBorders;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> Name;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess), Category = "YJCharacterSelectButtonWidget")
	int32 CharacterIndex = 0;

private:

	const int32 BORDER_COUNT = 4;
};
