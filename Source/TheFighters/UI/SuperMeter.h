

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SuperMeter.generated.h"

/**
 * 
 */
UCLASS()
class THEFIGHTERS_API USuperMeter : public UUserWidget
{
	GENERATED_BODY()

public:
    // 슈퍼미터 업데이트 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateSuperMeter(float CurrentSuperMeter);

protected:
    virtual void NativeConstruct() override;

private:
    // Progress Bar 바인딩
    UPROPERTY(meta = (BindWidget))
    class UProgressBar* SuperMeterProgressBar;

};
