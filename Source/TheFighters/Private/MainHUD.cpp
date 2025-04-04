// MainHUD.cpp
#include "MainHUD.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "PlayerUI.h"

void UMainHUD::NativeConstruct()
{
    Super::NativeConstruct();

    // �ʱ�ȭ �� �� �÷��̾� UI ���� �� �߰�
    for (int32 i = 0; i < 4; ++i) // 4���� �÷��̾� ����
    {
        if (UClass* PlayerUIClass = LoadClass<UUserWidget>(nullptr, TEXT("/Game/UI/WBP_PlayerUI.WBP_PlayerUI_C")))
        {
            UPlayerUI* NewPlayerUI = CreateWidget<UPlayerUI>(GetWorld(), PlayerUIClass);
            if (NewPlayerUI && PlayerUIContainer)
            {
                PlayerUIs.Add(NewPlayerUI);
                //PlayerUIContainer->AddChildToVerticalBox(NewPlayerUI); //��Ƽ�ÿ��� ĵ�۽��� �ٲ��� 
            }
        }
    }
}

void UMainHUD::UpdatePlayerUI(int32 PlayerIndex, float Health, float SuperMeter)
{
    if (PlayerUIs.IsValidIndex(PlayerIndex))
    {
        PlayerUIs[PlayerIndex]->UpdateHealth(Health);
        PlayerUIs[PlayerIndex]->UpdateSuperMeter(SuperMeter);
    }
}