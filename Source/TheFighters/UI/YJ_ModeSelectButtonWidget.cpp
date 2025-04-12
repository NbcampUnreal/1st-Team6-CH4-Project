#include "UI/YJ_ModeSelectButtonWidget.h"

#include "Components/Button.h"
#include "Components/RichTextBlock.h"

void UYJ_ModeSelectButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button->OnClicked.AddDynamic(this, &UYJ_ModeSelectButtonWidget::OnButtonClicked);
}

void UYJ_ModeSelectButtonWidget::ChangeModeText(bool bShouldChangeToCPUMode)
{
	if (bShouldChangeToCPUMode)
	{
		ButtonText->SetText(FText::FromString(TEXT("CPU Mode")));
	}
	else
	{
		ButtonText->SetText(FText::FromString(TEXT("PvP Mode")));
	}
}

void UYJ_ModeSelectButtonWidget::OnButtonClicked()
{
	OnModeSelectButtonClickedDelegate.Broadcast();
}
