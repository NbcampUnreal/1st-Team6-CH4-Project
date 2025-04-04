

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class THEFIGHTERS_API UMainHUD : public UUserWidget
{
	GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    // 특정 플레이어의 UI 업데이트 함수
    void UpdatePlayerUI(int32 PlayerIndex, float Health, float SuperMeter);

protected:
    // 플레이어 UI 배열
    UPROPERTY(meta = (BindWidget))
    class UCanvasPanel* PlayerUIContainer;

private:
    TArray<class UPlayerUI*> PlayerUIs;
};
