

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
    // 타이머 업데이트 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateTimer(float RemainingTime);

protected:
    virtual void NativeConstruct() override;

private:
    // 타이머 텍스트 바인딩
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* TimerText;
};

