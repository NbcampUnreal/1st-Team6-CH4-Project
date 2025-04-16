


#include "PlayerUI.h"
#include "HealthBar.h"
#include "LifeCounter.h"
#include "SuperMeter.h"
#include "Timer.h"
#include "Components/ProgressBar.h"


void UPlayerUI::NativeConstruct()
{
    Super::NativeConstruct();

    // Bind된 개별 위젯을 배열에 추가
    if (LifeCounter1) LifeCounters.Add(LifeCounter1);
    if (LifeCounter2) LifeCounters.Add(LifeCounter2);
    if (LifeCounter3) LifeCounters.Add(LifeCounter3);
}



float UPlayerUI::GetCurrentHealth() const
{
    // 플레이어에서 값 가져오기 todo:
    return 0.0f;
}

float UPlayerUI::GetCurrentSuperMeter() const
{
    // 플레이어에서 값 가져오기 todo:
    return 0.0f;
}

int32 UPlayerUI::GetRemainingLives() const
{
    // 플레이어에서 값 가져오기 todo:
    return int32();
}



void UPlayerUI::UpdateLives(int32 RemainingLives)
{
    for (int32 i = 0; i < LifeCounters.Num(); i++)
    {
        if (LifeCounters[i])
        {

            // 남은 목숨보다 작은 인덱스는 Visible, 나머지는 Hidden
            LifeCounters[i]->SetVisibility(i < RemainingLives ? ESlateVisibility::Visible : ESlateVisibility::Hidden);

            // ; 각각의 Life 마다 적용할 것 있다면? 색깔 등등
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
        Brush.ImageSize = FVector2D(100.f, 100.f); // 원하는 사이즈
        PlayerPortraitImage->SetBrush(Brush);
    }
}

void UPlayerUI::SetPlayerNumber(UTexture2D* PlayerNumberTexture)
{
    if (PlayerNumberImage && PlayerNumberTexture)
    {
        FSlateBrush Brush;
        Brush.SetResourceObject(PlayerNumberTexture);
        Brush.ImageSize = FVector2D(100.f, 100.f); // 원하는 사이즈
        PlayerNumberImage->SetBrush(Brush);
    }
}

void UPlayerUI::UpdateHealth(float CurrentHealth)
{
    if (HealthBar)
    {
        // HealthBar코드로 
        UHealthBar* PlayerHealthBar = Cast<UHealthBar>(HealthBar);
        PlayerHealthBar->UpdateHealth(CurrentHealth);
    }
}

void UPlayerUI::UpdateSuperMeter(float CurrentSuperMeter)
{
    if (SuperMeterBar)
    {
        // SuperMeterBar 코드로 
        USuperMeter* PlayerSuperMeterBar = Cast<USuperMeter>(SuperMeterBar);
        PlayerSuperMeterBar->UpdateSuperMeter(CurrentSuperMeter);
    }
}

