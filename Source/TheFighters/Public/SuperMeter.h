

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
    // ���۹��� ������Ʈ �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateSuperMeter(float CurrentSuperMeter);

protected:
    virtual void NativeConstruct() override;

private:
    // Progress Bar ���ε�
    UPROPERTY(meta = (BindWidget))
    class UProgressBar* SuperMeterProgressBar;

};
