


#include "PlayerUI.h"
#include "HealthBar.h"
#include "LifeCounter.h"
#include "SuperMeter.h"
#include "Timer.h"
#include "Components/ProgressBar.h"


void UPlayerUI::NativeConstruct()
{
    Super::NativeConstruct();

    // Bind�� ���� ������ �迭�� �߰�
    if (LifeCounter1) LifeCounters.Add(LifeCounter1);
    if (LifeCounter2) LifeCounters.Add(LifeCounter2);
    if (LifeCounter3) LifeCounters.Add(LifeCounter3);
}



float UPlayerUI::GetCurrentHealth() const
{
    // �÷��̾�� �� �������� todo:
    return 0.0f;
}

float UPlayerUI::GetCurrentSuperMeter() const
{
    // �÷��̾�� �� �������� todo:
    return 0.0f;
}

int32 UPlayerUI::GetRemainingLives() const
{
    // �÷��̾�� �� �������� todo:
    return int32();
}



void UPlayerUI::UpdateLives(int32 RemainingLives)
{
    for (int32 i = 0; i < LifeCounters.Num(); i++)
    {
        if (LifeCounters[i])
        {

            // ���� ������� ���� �ε����� Visible, �������� Hidden
            LifeCounters[i]->SetVisibility(i < RemainingLives ? ESlateVisibility::Visible : ESlateVisibility::Hidden);

            // ; ������ Life ���� ������ �� �ִٸ�? ���� ���
            ULifeCounter* LifeCounter = Cast<ULifeCounter>(LifeCounters[i]);
            LifeCounter->UpdateLives(RemainingLives);
        }
    }

}


void UPlayerUI::SetPlayerPortrait(UTexture2D* PortraitTexture)
{
    if (PlayerPortraitImage && PortraitTexture)
    {
        FSlateBrush Brush;
        Brush.SetResourceObject(PortraitTexture);
        Brush.ImageSize = FVector2D(100.f, 100.f); // ���ϴ� ������
        PlayerPortraitImage->SetBrush(Brush);
    }
}

void UPlayerUI::SetPlayerNumber(UTexture2D* PlayerNumberTexture)
{
    if (PlayerNumberImage && PlayerNumberTexture)
    {
        FSlateBrush Brush;
        Brush.SetResourceObject(PlayerNumberTexture);
        Brush.ImageSize = FVector2D(100.f, 100.f); // ���ϴ� ������
        PlayerNumberImage->SetBrush(Brush);
    }
}

void UPlayerUI::UpdateHealth(float CurrentHealth)
{
    if (HealthBar)
    {
        // HealthBar�ڵ�� 
        UHealthBar* PlayerHealthBar = Cast<UHealthBar>(HealthBar);
        PlayerHealthBar->UpdateHealth(CurrentHealth);
    }
}

void UPlayerUI::UpdateSuperMeter(float CurrentSuperMeter)
{
    if (SuperMeterBar)
    {
        // SuperMeterBar �ڵ�� 
        USuperMeter* PlayerSuperMeterBar = Cast<USuperMeter>(SuperMeterBar);
        PlayerSuperMeterBar->UpdateSuperMeter(CurrentSuperMeter);
    }
}

