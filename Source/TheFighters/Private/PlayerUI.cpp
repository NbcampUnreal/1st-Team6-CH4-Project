


#include "PlayerUI.h"
#include "Components/ProgressBar.h"

void UPlayerUI::UpdateLives(int32 RemainingLives)
{
    for (int32 i = 0; i < LifeCounters.Num(); i++)
    {
        if (LifeCounters[i])
        {
            // 남은 목숨보다 작은 인덱스는 Visible, 나머지는 Hidden
            LifeCounters[i]->SetVisibility(i < RemainingLives ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
        }
    }

}

void UPlayerUI::NativeConstruct()
{
	Super::NativeConstruct();

    // Bind된 개별 위젯을 배열에 추가
    if (LifeCounter1) LifeCounters.Add(LifeCounter1);
    if (LifeCounter2) LifeCounters.Add(LifeCounter2);
    if (LifeCounter3) LifeCounters.Add(LifeCounter3);
}


void UPlayerUI::UpdateHealth(float CurrentHealth)
{
    if (HealthBar)
    {

        //HealthBar->SetPercent(CurrentHealth); // 체력을 0~1 사이 값으로 설정
    }
}

void UPlayerUI::UpdateSuperMeter(float CurrentSuperMeter)
{
    //SuperMeterBar->SetPercent(CurrentSuperMeter); // 슈퍼미터를 0~1 사이 값으로 설정
}

