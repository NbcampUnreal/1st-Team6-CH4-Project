

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerUI.generated.h"

/**
 * 
 */
UCLASS()
class THEFIGHTERS_API UPlayerUI : public UUserWidget
{
	GENERATED_BODY()

public:
    // ü�� ������Ʈ �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateHealth(float CurrentHealth);

    // ���۹��� ������Ʈ �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateSuperMeter(float CurrentSuperMeter);

protected:
    virtual void NativeConstruct() override;

    // ü�°� ���۹��� ���� ���ε�
    UPROPERTY(meta = (BindWidget))
    class UProgressBar* HealthBar;

    UPROPERTY(meta = (BindWidget))
    class UProgressBar* SuperMeterBar;
};
