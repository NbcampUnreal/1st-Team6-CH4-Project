// MainHUD.cpp
#include "MainHUD.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "PlayerUI.h"

void UMainHUD::NativeConstruct()
{
    Super::NativeConstruct();

    // 초기화 시 각 플레이어 UI 생성 및 추가
    for (int32 i = 0; i < 4; ++i) // 4명의 플레이어 기준
    {
        if (UClass* PlayerUIClass = LoadClass<UUserWidget>(nullptr, TEXT("/Game/UI/WBP_PlayerUI.WBP_PlayerUI_C")))
        {
            UPlayerUI* NewPlayerUI = CreateWidget<UPlayerUI>(GetWorld(), PlayerUIClass);
            if (NewPlayerUI && PlayerUIContainer)
            {
                PlayerUIs.Add(NewPlayerUI);
                //PlayerUIContainer->AddChildToVerticalBox(NewPlayerUI); //버티컬에서 캔퍼스로 바꿨음 
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