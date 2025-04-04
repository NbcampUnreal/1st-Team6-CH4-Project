


#include "PlayerUI.h"
#include "Components/ProgressBar.h"

void UPlayerUI::UpdateLives(int32 RemainingLives)
{
    for (int32 i = 0; i < LifeCounters.Num(); i++)
    {
        if (LifeCounters[i])
        {
            // ���� ������� ���� �ε����� Visible, �������� Hidden
            LifeCounters[i]->SetVisibility(i < RemainingLives ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
        }
    }

}

void UPlayerUI::NativeConstruct()
{
	Super::NativeConstruct();

    // Bind�� ���� ������ �迭�� �߰�
    if (LifeCounter1) LifeCounters.Add(LifeCounter1);
    if (LifeCounter2) LifeCounters.Add(LifeCounter2);
    if (LifeCounter3) LifeCounters.Add(LifeCounter3);
}


void UPlayerUI::UpdateHealth(float CurrentHealth)
{
    if (HealthBar)
    {

        //HealthBar->SetPercent(CurrentHealth); // ü���� 0~1 ���� ������ ����
    }
}

void UPlayerUI::UpdateSuperMeter(float CurrentSuperMeter)
{
    //SuperMeterBar->SetPercent(CurrentSuperMeter); // ���۹��͸� 0~1 ���� ������ ����
}

