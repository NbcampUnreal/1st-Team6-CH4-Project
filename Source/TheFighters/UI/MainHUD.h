

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
    


    // ���� UI ���� �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetPlayerUIVisibility(int32 PlayerIndex, bool bIsVisible);

    // Ÿ�̸� ���� �״� �ϴ� �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetTimerVisibility(bool bIsVisible);

    // Ư�� �÷��̾��� ��üUI ������Ʈ �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdatePlayerUI(int32 PlayerIndex, float Health, float SuperMeter, int32 Lives);
    // Ÿ�̸� ������Ʈ �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateTimer(float RemainingTime);



    // ���� ������ ������Ʈ �Լ�
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
    // Timer ���� ���ε�
    UPROPERTY(meta = (BindWidget))
    class UUserWidget* TimerWidget;

    // Player�� Player1�� ���� ���� ����
    UPROPERTY(meta = (BindWidget))
    class UPlayerUI* Player; // ���� ��� ū UI

    UPROPERTY(meta = (BindWidget))
    class UPlayerUI* Player1; // Player�� ������ ������ ����

    // ������ �÷��̾� UI
    UPROPERTY(meta = (BindWidget))
    class UPlayerUI* Player2;

    UPROPERTY(meta = (BindWidget))
    class UPlayerUI* Player3;

    UPROPERTY(meta = (BindWidget))
    class UPlayerUI* Player4;

private:
    // ������ �÷��̾� UI�� �迭�� ����
    TArray<class UPlayerUI*> OtherPlayers;

    int32 OwnerPlayerIndex = 0;
};


