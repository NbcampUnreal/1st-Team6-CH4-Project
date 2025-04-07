


#include "HealthBar.h"
#include "Components/ProgressBar.h"

void UHealthBar::NativeConstruct()
{
    Super::NativeConstruct();

    // 초기화 작업 필요 시 여기에 추가 가능
}


void UHealthBar::UpdateHealth(float CurrentHealth)
{
    if (HealthProgressBar)
    {
        HealthProgressBar->SetPercent(CurrentHealth); // 체력을 0~1 사이 값으로 설정
    }
}

