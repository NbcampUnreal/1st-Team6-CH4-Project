

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
    void UpdatePlayerUI(int32 PlayerIndex, float Health, float SuperMeter);

protected:
    // �÷��̾� UI �迭
    UPROPERTY(meta = (BindWidget))
    class UCanvasPanel* PlayerUIContainer;

private:
    TArray<class UPlayerUI*> PlayerUIs;
};
