

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
    // ü�� ������Ʈ �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateHealth(float CurrentHealth);

protected:
    virtual void NativeConstruct() override;

    // Progress Bar ���ε�
    UPROPERTY(meta = (BindWidget))
    class UProgressBar* HealthProgressBar;
	
};
