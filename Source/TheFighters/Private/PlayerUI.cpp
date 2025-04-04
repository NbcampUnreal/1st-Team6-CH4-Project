


#include "PlayerUI.h"
#include "Components/ProgressBar.h"

void UPlayerUI::NativeConstruct()
{
	Super::NativeConstruct();

}


void UPlayerUI::UpdateHealth(float CurrentHealth)
{
    if (HealthBar)
    {
        HealthBar->SetPercent(CurrentHealth); // 체력을 0~1 사이 값으로 설정
    }
}

void UPlayerUI::UpdateSuperMeter(float CurrentSuperMeter)
{
    SuperMeterBar->SetPercent(CurrentSuperMeter); // 슈퍼미터를 0~1 사이 값으로 설정
}

