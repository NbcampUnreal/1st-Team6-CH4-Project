

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
    // ��� ������Ʈ �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateLives(int32 RemainingLives);

protected:
    virtual void NativeConstruct() override;

private:
    // ��� ǥ�ÿ� �ؽ�Ʈ ���ε� ; or �̹����� ��Ÿ���� 
    //UPROPERTY(meta = (BindWidget))
    //class UTextBlock* LivesText;
};
