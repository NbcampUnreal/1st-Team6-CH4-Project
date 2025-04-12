#include "UI/YJ_CharacterSelectButtonWidget.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UYJ_CharacterSelectButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button->OnClicked.AddDynamic(this, &UYJ_CharacterSelectButtonWidget::OnCharacterSelectButtonClicked);

	FString BorderText = TEXT("BorderP");

	for (int32 i = 0; i < BORDER_COUNT; ++i)
	{
		UImage* BorderIamge = CastChecked<UImage>(GetWidgetFromName(FName(FString::Printf(TEXT("%s%s"), *BorderText, *FString::FromInt(i + 1)))));
		PlayerBorders.Emplace(BorderIamge);
	}
}

void UYJ_CharacterSelectButtonWidget::SetActivePlayerBorder(int32 PlayerIndex, bool bShouldActivate)
{
	UE_LOG(LogTemp, Error, TEXT("Player Index : %d, Visible : %d"), PlayerIndex, bShouldActivate);

	ESlateVisibility NewVisibility = (bShouldActivate) ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Hidden;
	PlayerBorders[PlayerIndex]->SetVisibility(NewVisibility);
}

void UYJ_CharacterSelectButtonWidget::SetNameText(const FString& NewNameText)
{
	Name->SetText(FText::FromString(NewNameText));
}

void UYJ_CharacterSelectButtonWidget::OnCharacterSelectButtonClicked()
{
	OnCharacterSelectButtonClickedDelegate.Broadcast(CharacterIndex);
}
