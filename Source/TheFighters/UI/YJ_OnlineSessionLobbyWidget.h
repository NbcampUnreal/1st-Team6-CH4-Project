#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "YJ_EnumContainer.h"

#include "YJ_OnlineSessionLobbyWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMapButtonClickedDelegate, int32, SelectedIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterButtonClickedDelegate, int32, SelectedIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReadyStartButtonClickedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnModeButtonClickedDelegate);

class UYJ_CharacterSelectButtonWidget;
class UYJ_MapSelectButtonWidget;
class URichTextBlock;
class UYJ_ReadyAndStartButtonWidget;
class UYJ_ModeSelectButtonWidget;

/**
 * 
 */
UCLASS()
class THEFIGHTERS_API UYJ_OnlineSessionLobbyWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativeConstruct() override;

public:

	UPROPERTY(BlueprintAssignable, Category = "YJOnlineSessionLobbyWidget")
	FOnMapButtonClickedDelegate OnMapButtonClickedDelegate;

	UPROPERTY(BlueprintAssignable, Category = "YJOnlineSessionLobbyWidget")
	FOnCharacterButtonClickedDelegate OnCharacterButtonClickedDelegate;

	UPROPERTY(BlueprintAssignable, Category = "YJOnlineSessionLobbyWidget")
	FOnReadyStartButtonClickedDelegate OnReadyStartButtonClickedDelegate;

	UPROPERTY(BlueprintAssignable, Category = "YJOnlineSessionLobbyWidget")
	FOnModeButtonClickedDelegate OnModeButtonClickedDelegate;

public:

	UFUNCTION(BlueprintCallable, Category = "YJOnlineSessionLobbyWidget")
	void SetActivePlayerText(int32 PlayerIndex, bool bShouldActivate);

	// 0번이 첫 번째
	UFUNCTION(BlueprintCallable, Category = "YJOnlineSessionLobbyWidget")
	UYJ_CharacterSelectButtonWidget* GetCharactSelectButton(int32 ButtonIndex) const;

	// 0번이 첫 번째
	UFUNCTION(BlueprintCallable, Category = "YJOnlineSessionLobbyWidget")
	UYJ_MapSelectButtonWidget* GetMapSelectButton(int32 ButtonIndex) const;

	UFUNCTION(BlueprintCallable, Category = "YJOnlineSessionLobbyWidget")
	URichTextBlock* GetPlayerText(int32 PlayerIndex) const;

	UFUNCTION(BlueprintCallable, Category = "YJOnlineSessionLobbyWidget")
	UYJ_ReadyAndStartButtonWidget* GetReadyAndStartButton() const;

	UFUNCTION(BlueprintCallable, Category = "YJOnlineSessionLobbyWidget")
	UYJ_ModeSelectButtonWidget* GetModeSelectButton() const;

private:

	UFUNCTION()
	void OnMapButtonClicked(int32 SelectedIndex);

	UFUNCTION()
	void OnCharacterButtonClicked(int32 SelectedIndex);

	UFUNCTION()
	void OnReadyAndStartButtonClicked();

	UFUNCTION()
	void OnModeButtonClicked();

private:

	UPROPERTY()
	TArray<TObjectPtr<UYJ_CharacterSelectButtonWidget>> CharacterSelectButtons;
	
	UPROPERTY()
	TArray<TObjectPtr<UYJ_MapSelectButtonWidget>> MapSelectButtons;

	UPROPERTY()
	TArray<TObjectPtr<URichTextBlock>> PlayerTexts;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UYJ_ReadyAndStartButtonWidget> ReadyAndStartButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UYJ_ModeSelectButtonWidget> ModeSelectButton;



};
