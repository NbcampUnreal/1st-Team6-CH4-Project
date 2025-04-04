


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
        HealthBar->SetPercent(CurrentHealth); // ü���� 0~1 ���� ������ ����
    }
}

void UPlayerUI::UpdateSuperMeter(float CurrentSuperMeter)
{
    SuperMeterBar->SetPercent(CurrentSuperMeter); // ���۹��͸� 0~1 ���� ������ ����
}

