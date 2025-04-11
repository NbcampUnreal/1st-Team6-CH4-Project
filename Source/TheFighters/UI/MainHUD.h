

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
    


    // 개별 UI 끄는 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetPlayerUIVisibility(int32 PlayerIndex, bool bIsVisible);

    // 타이머 껐다 켰다 하는 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetTimerVisibility(bool bIsVisible);

    // 특정 플레이어의 전체UI 업데이트 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdatePlayerUI(int32 PlayerIndex, float Health, float SuperMeter, int32 Lives);
    // 타이머 업데이트 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateTimer(float RemainingTime);



    // 개별 데이터 업데이트 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdatePlayerHealth(int32 PlayerIndex, float Health);
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdatePlayerSuperMeter(int32 PlayerIndex, float SuperMeter);
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdatePlayerLives(int32 PlayerIndex, int32 Lives);



public:

    UFUNCTION(BlueprintCallable)
    void SetOwnerPlayerIndex(int32 NewPlayerIndex);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetOnwerPlayerIndex() const;

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

    int32 OwnerPlayerIndex = 0;
};


