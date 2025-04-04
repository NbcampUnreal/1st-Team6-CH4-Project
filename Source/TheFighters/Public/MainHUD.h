

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

    // Ư�� �÷��̾��� UI ������Ʈ �Լ�
    void UpdatePlayerUI(int32 PlayerIndex, float Health, float SuperMeter, int32 Lives);
    // Ÿ�̸� ������Ʈ �Լ�
    void UpdateTimer(float RemainingTime);

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
};
