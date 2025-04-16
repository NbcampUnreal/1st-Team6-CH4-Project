// MainHUD.cpp
#include "MainHUD.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "PlayerUI.h"

void UMainHUD::NativeConstruct()
{
    Super::NativeConstruct();

    // OtherPlayers �迭 �ʱ�ȭ
    if (Player1) OtherPlayers.Add(Player1);
    if (Player2) OtherPlayers.Add(Player2);
    if (Player3) OtherPlayers.Add(Player3);
    if (Player4) OtherPlayers.Add(Player4);

    // Player�� Player1�� ���� �����͸� �����ϵ��� ����
    if (Player && Player1)
    {
        // �ʱ�ȭ �� ������ �����͸� ǥ��

        Player->UpdateHealth(Player1->GetCurrentHealth());
        Player->UpdateSuperMeter(Player1->GetCurrentSuperMeter());
        Player->UpdateLives(Player1->GetRemainingLives());
    }
}


void UMainHUD::SetPlayerUIVisibility(int32 PlayerIndex, bool bIsVisible)
{
    ESlateVisibility VisibilityState = bIsVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden;

    if (OtherPlayers.IsValidIndex(PlayerIndex)) // ������ �÷��̾�� ������Ʈ
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
        // 0 �� ���� ����� �÷��̾� ��ȣ ��Ÿ���� �ʰ�
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
    if (PlayerIndex == OwnerPlayerIndex) // Player1�� OwnerPlayer�� ���� �����͸� ����
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

    if (OtherPlayers.IsValidIndex(PlayerIndex)) // ������ �÷��̾�� ������Ʈ
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
        // Timer ������ ���� �ð��� ǥ���ϴ� ���� �߰�
        // ��: TimerWidget�� �ؽ�Ʈ�� ������Ʈ�ϰų� ProgressBar�� ����
        // TimerWidget->SetText(FText::AsNumber(RemainingTime));
    }
}


void UMainHUD::UpdatePlayerHealth(int32 PlayerIndex, float Health)
{
    if (PlayerIndex == OwnerPlayerIndex) // Player�� OwnerPlayer�� ���� �����͸� ����
    {
        if (Player)
            Player->UpdateHealth(Health);
        /*if (Player1)
            Player1->UpdateHealth(Health);*/
    }

    if (OtherPlayers.IsValidIndex(PlayerIndex)) // ������ �÷��̾�� ������Ʈ
    {
        UPlayerUI* TargetPlayerUI = OtherPlayers[PlayerIndex];
        if (TargetPlayerUI)
            TargetPlayerUI->UpdateHealth(Health);
    }
}

void UMainHUD::UpdatePlayerSuperMeter(int32 PlayerIndex, float SuperMeter)
{
    if (PlayerIndex == OwnerPlayerIndex) // Player�� OwnerPlayer�� ���� �����͸� ����
    {
        if (Player)
            Player->UpdateSuperMeter(SuperMeter);

        /*if (Player1)
            Player1->UpdateSuperMeter(SuperMeter);*/
    }

    if (OtherPlayers.IsValidIndex(PlayerIndex)) // ������ �÷��̾�� ������Ʈ
    {
        UPlayerUI* TargetPlayerUI = OtherPlayers[PlayerIndex];
        if (TargetPlayerUI)
            TargetPlayerUI->UpdateSuperMeter(SuperMeter);
    }
}

void UMainHUD::UpdatePlayerLives(int32 PlayerIndex, int32 Lives)
{
    if (PlayerIndex == OwnerPlayerIndex) // Player�� OwnerPlayer�� ���� �����͸� ����
    {
        if (Player)
            Player->UpdateLives(Lives);

        /*if (Player1)
            Player1->UpdateLives(Lives);*/
    }

    if (OtherPlayers.IsValidIndex(PlayerIndex)) // ������ �÷��̾�� ������Ʈ
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

