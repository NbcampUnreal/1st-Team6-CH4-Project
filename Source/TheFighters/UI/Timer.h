

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Timer.generated.h"

/**
 * 
 */
UCLASS()
class THEFIGHTERS_API UTimer : public UUserWidget
{
	GENERATED_BODY()
	
public:
    // Ÿ�̸� ������Ʈ �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateTimer(float RemainingTime);

protected:
    virtual void NativeConstruct() override;

private:
    // Ÿ�̸� �ؽ�Ʈ ���ε�
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* TimerText;
};

