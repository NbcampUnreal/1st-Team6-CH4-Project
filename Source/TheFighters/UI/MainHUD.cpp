// MainHUD.cpp
#include "MainHUD.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "PlayerUI.h"

void UMainHUD::NativeConstruct()
{
    Super::NativeConstruct();

    // OtherPlayers 배열 초기화
    if (Player1) OtherPlayers.Add(Player1);
    if (Player2) OtherPlayers.Add(Player2);
    if (Player3) OtherPlayers.Add(Player3);
    if (Player4) OtherPlayers.Add(Player4);

    // Player와 Player1은 같은 데이터를 공유하도록 설정
    if (Player && Player1)
    {
        // 초기화 시 동일한 데이터를 표시

        Player->UpdateHealth(Player1->GetCurrentHealth());
        Player->UpdateSuperMeter(Player1->GetCurrentSuperMeter());
        Player->UpdateLives(Player1->GetRemainingLives());
    }
}


void UMainHUD::SetPlayerUIVisibility(int32 PlayerIndex, bool bIsVisible)
{
    ESlateVisibility VisibilityState = bIsVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden;

    if (OtherPlayers.IsValidIndex(PlayerIndex)) // 나머지 플레이어들 업데이트
    {
        UPlayerUI* TargetPlayerUI = OtherPlayers[PlayerIndex];
        if (TargetPlayerUI)
            TargetPlayerUI->SetVisibility(VisibilityState);
    }
}

void UMainHUD::SetPlayerImageVisibility(int32 PlayerIndex, bool bIsVisible)
{

}

void UMainHUD::SetPlayerPortrait(int32 PlayerIndex, UTexture2D* NewPortrait)
{
    if (PlayerIndex == OwnerPlayerIndex)
    {
        Player->SetPlayerPortrait(NewPortrait);
    }

    OtherPlayers[PlayerIndex]->SetPlayerPortrait(NewPortrait);
}

void UMainHUD::SetPlayerNumber(int32 PlayerIndex, UTexture2D* NewNumber)
{

    if (PlayerIndex == OwnerPlayerIndex)
    {
        // 0 번 왼쪽 상단은 플레이어 번호 나타나지 않게
        //Player->SetPlayerNumber(NewNumber);
        
    }

    OtherPlayers[PlayerIndex]->SetPlayerNumber(NewNumber);
}

void UMainHUD::SetTimerVisibility(bool bIsVisible)
{
    ESlateVisibility VisibilityState = bIsVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden;

    if (TimerWidget)
        TimerWidget->SetVisibility(VisibilityState);

}

void UMainHUD::UpdatePlayerUI(int32 PlayerIndex, float Health, float SuperMeter, int32 Lives)
{
    if (PlayerIndex == OwnerPlayerIndex) // Player1과 OwnerPlayer가 같은 데이터를 공유
    {
        if (Player)
        {
            Player->UpdateHealth(Health);
            Player->UpdateSuperMeter(SuperMeter);
            Player->UpdateLives(Lives);
        }

        /*if (Player1)
        {
            Player1->UpdateHealth(Health);
            Player1->UpdateSuperMeter(SuperMeter);
            Player1->UpdateLives(Lives);
        }*/
    }

    if (OtherPlayers.IsValidIndex(PlayerIndex)) // 나머지 플레이어들 업데이트
    {
        UPlayerUI* TargetPlayerUI = OtherPlayers[PlayerIndex];
        if (TargetPlayerUI)
        {
            TargetPlayerUI->UpdateHealth(Health);
            TargetPlayerUI->UpdateSuperMeter(SuperMeter);
            TargetPlayerUI->UpdateLives(Lives);
        }
    }
}

void UMainHUD::UpdateTimer(float RemainingTime)
{
    if (TimerWidget)
    {
        // Timer 위젯에 남은 시간을 표시하는 로직 추가
        // 예: TimerWidget의 텍스트를 업데이트하거나 ProgressBar를 조정
        // TimerWidget->SetText(FText::AsNumber(RemainingTime));
    }
}


void UMainHUD::UpdatePlayerHealth(int32 PlayerIndex, float Health)
{
    if (PlayerIndex == OwnerPlayerIndex) // Player와 OwnerPlayer이 같은 데이터를 공유
    {
        if (Player)
            Player->UpdateHealth(Health);
        /*if (Player1)
            Player1->UpdateHealth(Health);*/
    }

    if (OtherPlayers.IsValidIndex(PlayerIndex)) // 나머지 플레이어들 업데이트
    {
        UPlayerUI* TargetPlayerUI = OtherPlayers[PlayerIndex];
        if (TargetPlayerUI)
            TargetPlayerUI->UpdateHealth(Health);
    }
}

void UMainHUD::UpdatePlayerSuperMeter(int32 PlayerIndex, float SuperMeter)
{
    if (PlayerIndex == OwnerPlayerIndex) // Player와 OwnerPlayer이 같은 데이터를 공유
    {
        if (Player)
            Player->UpdateSuperMeter(SuperMeter);

        /*if (Player1)
            Player1->UpdateSuperMeter(SuperMeter);*/
    }

    if (OtherPlayers.IsValidIndex(PlayerIndex)) // 나머지 플레이어들 업데이트
    {
        UPlayerUI* TargetPlayerUI = OtherPlayers[PlayerIndex];
        if (TargetPlayerUI)
            TargetPlayerUI->UpdateSuperMeter(SuperMeter);
    }
}

void UMainHUD::UpdatePlayerLives(int32 PlayerIndex, int32 Lives)
{
    if (PlayerIndex == OwnerPlayerIndex) // Player와 OwnerPlayer이 같은 데이터를 공유
    {
        if (Player)
            Player->UpdateLives(Lives);

        /*if (Player1)
            Player1->UpdateLives(Lives);*/
    }

    if (OtherPlayers.IsValidIndex(PlayerIndex)) // 나머지 플레이어들 업데이트
    {
        UPlayerUI* TargetPlayerUI = OtherPlayers[PlayerIndex];
        if (TargetPlayerUI)
            TargetPlayerUI->UpdateLives(Lives);
    }
}

void UMainHUD::SetOwnerPlayerIndex(int32 NewPlayerIndex)
{
    OwnerPlayerIndex = NewPlayerIndex;
}

int32 UMainHUD::GetOnwerPlayerIndex() const
{
    return OwnerPlayerIndex;
}

