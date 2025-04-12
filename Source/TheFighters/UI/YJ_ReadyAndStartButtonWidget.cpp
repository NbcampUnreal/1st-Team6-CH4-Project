#include "UI/YJ_ReadyAndStartButtonWidget.h"

#include "Components/RichTextBlock.h"
#include "Components/Button.h"

void UYJ_ReadyAndStartButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button->OnClicked.AddDynamic(this, &UYJ_ReadyAndStartButtonWidget::OnButtonClicked);
}

void UYJ_ReadyAndStartButtonWidget::OnButtonClicked()
{
	OnReadyAndStartButtonClickedDelegate.Broadcast();
}
