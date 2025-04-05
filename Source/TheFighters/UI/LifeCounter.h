

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LifeCounter.generated.h"

/**
 * 
 */
UCLASS()
class THEFIGHTERS_API ULifeCounter : public UUserWidget
{
	GENERATED_BODY()

public:
    // 목숨 업데이트 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateLives(int32 RemainingLives);

protected:
    virtual void NativeConstruct() override;

private:
    // 목숨 표시용 텍스트 바인딩 ; or 이미지로 나타내기 
    //UPROPERTY(meta = (BindWidget))
    //class UTextBlock* LivesText;
};
