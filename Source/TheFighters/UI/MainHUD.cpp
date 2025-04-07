// MainHUD.cpp
#include "MainHUD.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "PlayerUI.h"

void UMainHUD::NativeConstruct()
{
    Super::NativeConstruct();

    // OtherPlayers �迭 �ʱ�ȭ
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

void UMainHUD::UpdatePlayerUI(int32 PlayerIndex, float Health, float SuperMeter, int32 Lives)
{
    if (PlayerIndex == 0) // Player1�� Player�� ���� �����͸� ����
    {
        if (Player)
        {
            Player->UpdateHealth(Health);
            Player->UpdateSuperMeter(SuperMeter);
            Player->UpdateLives(Lives);
        }

        if (Player1)
        {
            Player1->UpdateHealth(Health);
            Player1->UpdateSuperMeter(SuperMeter);
            Player1->UpdateLives(Lives);
        }
    }
    else if (OtherPlayers.IsValidIndex(PlayerIndex - 1)) // ������ �÷��̾�� ������Ʈ
    {
        UPlayerUI* TargetPlayerUI = OtherPlayers[PlayerIndex - 1];
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
    if (PlayerIndex == 0) // Player�� Player1�� ���� �����͸� ����
    {
        if (Player)
            Player->UpdateHealth(Health);

        if (Player1)
            Player1->UpdateHealth(Health);
    }
    else if (OtherPlayers.IsValidIndex(PlayerIndex - 1)) // ������ �÷��̾�� ������Ʈ
    {
        UPlayerUI* TargetPlayerUI = OtherPlayers[PlayerIndex - 1];
        if (TargetPlayerUI)
            TargetPlayerUI->UpdateHealth(Health);
    }
}

void UMainHUD::UpdatePlayerSuperMeter(int32 PlayerIndex, float SuperMeter)
{
    if (PlayerIndex == 0) // Player�� Player1�� ���� �����͸� ����
    {
        if (Player)
            Player->UpdateSuperMeter(SuperMeter);

        if (Player1)
            Player1->UpdateSuperMeter(SuperMeter);
    }
    else if (OtherPlayers.IsValidIndex(PlayerIndex - 1)) // ������ �÷��̾�� ������Ʈ
    {
        UPlayerUI* TargetPlayerUI = OtherPlayers[PlayerIndex - 1];
        if (TargetPlayerUI)
            TargetPlayerUI->UpdateSuperMeter(SuperMeter);
    }
}

void UMainHUD::UpdatePlayerLives(int32 PlayerIndex, int32 Lives)
{

    if (PlayerIndex == 0) // Player�� Player1�� ���� �����͸� ����
    {
        if (Player)
            Player->UpdateLives(Lives);

        if (Player1)
            Player1->UpdateLives(Lives);
    }
    else if (OtherPlayers.IsValidIndex(PlayerIndex - 1)) // ������ �÷��̾�� ������Ʈ
    {
        UPlayerUI* TargetPlayerUI = OtherPlayers[PlayerIndex - 1];
        if (TargetPlayerUI)
            TargetPlayerUI->UpdateLives(Lives);
    }
}

