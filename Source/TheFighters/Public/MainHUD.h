

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
    void UpdatePlayerUI(int32 PlayerIndex, float Health, float SuperMeter, int32 Lives);
    // 타이머 업데이트 함수
    void UpdateTimer(float RemainingTime);

protected:
    // Timer 위젯 바인딩
    UPROPERTY(meta = (BindWidget))
    class UUserWidget* TimerWidget;

    // Player와 Player1은 같은 값을 공유
    UPROPERTY(meta = (BindWidget))
    class UPlayerUI* Player; // 왼쪽 상단 큰 UI

    UPROPERTY(meta = (BindWidget))
    class UPlayerUI* Player1; // Player와 동일한 데이터 공유

    // 나머지 플레이어 UI
    UPROPERTY(meta = (BindWidget))
    class UPlayerUI* Player2;

    UPROPERTY(meta = (BindWidget))
    class UPlayerUI* Player3;

    UPROPERTY(meta = (BindWidget))
    class UPlayerUI* Player4;

private:
    // 나머지 플레이어 UI를 배열로 관리
    TArray<class UPlayerUI*> OtherPlayers;
};
