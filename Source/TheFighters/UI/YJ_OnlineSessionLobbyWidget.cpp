#include "UI/YJ_OnlineSessionLobbyWidget.h"

#include "UI/YJ_CharacterSelectButtonWidget.h"
#include "UI/YJ_ReadyAndStartButtonWidget.h"
#include "UI/YJ_ModeSelectButtonWidget.h"
#include "UI/YJ_MapSelectButtonWidget.h"

#include "Components/RichTextBlock.h"

void UYJ_OnlineSessionLobbyWidget::NativeConstruct()
{
	Super::NativeConstruct();

	FString WidgetName = "";

	int32 CharacterSelectButtonCount = 5;
	FString SelectButtonText = TEXT("SelectButton");
	for (int32 i = 0; i < CharacterSelectButtonCount; ++i)
	{
		WidgetName  = FString::Printf(TEXT("%s%s"), *SelectButtonText, *FString::FromInt(i + 1));
		UYJ_CharacterSelectButtonWidget* CharacterSelectButtonWidget = CastChecked<UYJ_CharacterSelectButtonWidget>(GetWidgetFromName(FName(*WidgetName)));
		CharacterSelectButtons.Emplace(CharacterSelectButtonWidget);
		CharacterSelectButtonWidget->OnCharacterSelectButtonClickedDelegate.AddDynamic(this, &UYJ_OnlineSessionLobbyWidget::OnCharacterButtonClicked);
	}
	
	int32 PlayerTextCount = 4;
	FString PlayerTextStr = TEXT("PlayerText");

	for (int32 i = 0; i < PlayerTextCount; ++i)
	{
		WidgetName = FString::Printf(TEXT("%s%s"), *PlayerTextStr, *FString::FromInt(i + 1));
		URichTextBlock* TextBlock = CastChecked<URichTextBlock>(GetWidgetFromName(FName(*WidgetName)));
		PlayerTexts.Emplace(TextBlock);
	}

	int32 MapSelectButtonCount = 5;
	FString MapSelectButtonText = TEXT("MapSelectButton");
	for (int32 i = 0; i < MapSelectButtonCount; ++i)
	{
		WidgetName = FString::Printf(TEXT("%s%s"), *MapSelectButtonText, *FString::FromInt(i + 1));
		UE_LOG(LogTemp, Error, TEXT("Widget Name : %s"), *WidgetName);
		UYJ_MapSelectButtonWidget* MapSelectButton = CastChecked<UYJ_MapSelectButtonWidget>(GetWidgetFromName(FName(*WidgetName)));
		MapSelectButtons.Emplace(MapSelectButton);
		MapSelectButton->OnMapSelectButtonClickedDelegate.AddDynamic(this, &::UYJ_OnlineSessionLobbyWidget::OnMapButtonClicked);
	}

	ReadyAndStartButton->OnReadyAndStartButtonClickedDelegate.AddDynamic(this, &UYJ_OnlineSessionLobbyWidget::OnReadyAndStartButtonClicked);
	ModeSelectButton->OnModeSelectButtonClickedDelegate.AddDynamic(this, &UYJ_OnlineSessionLobbyWidget::OnModeButtonClicked);
}

void UYJ_OnlineSessionLobbyWidget::SetActivePlayerText(int32 PlayerIndex, bool bShouldActivate)
{
	if (bShouldActivate)
	{
		PlayerTexts[PlayerIndex]->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
	else
	{
		PlayerTexts[PlayerIndex]->SetVisibility(ESlateVisibility::Hidden);
	}
}

UYJ_CharacterSelectButtonWidget* UYJ_OnlineSessionLobbyWidget::GetCharactSelectButton(int32 ButtonIndex) const
{
	return CharacterSelectButtons[ButtonIndex];
}

UYJ_MapSelectButtonWidget* UYJ_OnlineSessionLobbyWidget::GetMapSelectButton(int32 ButtonIndex) const
{
	return MapSelectButtons[ButtonIndex];
}

URichTextBlock* UYJ_OnlineSessionLobbyWidget::GetPlayerText(int32 PlayerIndex) const
{
	return PlayerTexts[PlayerIndex];
}

UYJ_ReadyAndStartButtonWidget* UYJ_OnlineSessionLobbyWidget::GetReadyAndStartButton() const
{
	return ReadyAndStartButton;
}

UYJ_ModeSelectButtonWidget* UYJ_OnlineSessionLobbyWidget::GetModeSelectButton() const
{
	return ModeSelectButton;
}

void UYJ_OnlineSessionLobbyWidget::OnMapButtonClicked(int32 SelectedIndex)
{
	OnMapButtonClickedDelegate.Broadcast(SelectedIndex);
}

void UYJ_OnlineSessionLobbyWidget::OnCharacterButtonClicked(int32 SelectedIndex)
{
	OnCharacterButtonClickedDelegate.Broadcast(SelectedIndex);
}

void UYJ_OnlineSessionLobbyWidget::OnReadyAndStartButtonClicked()
{
	OnReadyStartButtonClickedDelegate.Broadcast();
}

void UYJ_OnlineSessionLobbyWidget::OnModeButtonClicked()
{
	OnModeButtonClickedDelegate.Broadcast();
}
