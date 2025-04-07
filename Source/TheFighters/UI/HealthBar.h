

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"

/**
 * 
 */
UCLASS()
class THEFIGHTERS_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()

public:
    // 체력 업데이트 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateHealth(float CurrentHealth);

protected:
    virtual void NativeConstruct() override;

    // Progress Bar 바인딩
    UPROPERTY(meta = (BindWidget))
    class UProgressBar* HealthProgressBar;
	
};
