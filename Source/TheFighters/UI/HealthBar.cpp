


#include "HealthBar.h"
#include "Components/ProgressBar.h"

void UHealthBar::NativeConstruct()
{
    Super::NativeConstruct();

    // �ʱ�ȭ �۾� �ʿ� �� ���⿡ �߰� ����
}


void UHealthBar::UpdateHealth(float CurrentHealth)
{
    if (HealthProgressBar)
    {
        HealthProgressBar->SetPercent(CurrentHealth); // ü���� 0~1 ���� ������ ����
    }
}

