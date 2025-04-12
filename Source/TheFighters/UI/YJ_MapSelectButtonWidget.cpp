#include "UI/YJ_MapSelectButtonWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UYJ_MapSelectButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button->OnClicked.AddDynamic(this, &UYJ_MapSelectButtonWidget::OnMapSelectButtonClicked);
}

void UYJ_MapSelectButtonWidget::SetActiveHighlight(bool bShouldActivate)
{
	ESlateVisibility NewVisibility = (bShouldActivate) ? ESlateVisibility::HitTestInvisible : ESlateVisibility::Hidden;

	HighLight->SetVisibility(NewVisibility);
}

void UYJ_MapSelectButtonWidget::OnMapSelectButtonClicked()
{
	OnMapSelectButtonClickedDelegate.Broadcast(MapIndex);
}
