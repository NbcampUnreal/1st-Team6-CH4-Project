

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "PlayerUI.generated.h"
/**
 * 
 */
UCLASS()
class THEFIGHTERS_API UPlayerUI : public UUserWidget
{
	GENERATED_BODY()

public:
    // ���� ĳ������ �ʻ�ȭ �����ϴ� �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetPlayerPortrait(UTexture2D* PortraitTexture);

    // ���� ĳ������ ��ȣ �����ϴ� �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetPlayerNumber(UTexture2D* PlayerNumberTexture);
    
public:
    // ü�� ������Ʈ �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateHealth(float CurrentHealth);

    // ���۹��� ������Ʈ �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateSuperMeter(float CurrentSuperMeter);

    // ��� ������Ʈ �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateLives(int32 RemainingLives);


protected:
    virtual void NativeConstruct() override;

    // ���� ĳ������ �ʻ�ȭ  
    UPROPERTY(meta = (BindWidget))
    class UImage* PlayerPortraitImage;


    // ���� ĳ������ �÷��̾��ȣ 
    UPROPERTY(meta = (BindWidget))
    class UImage* PlayerNumberImage;


    // ü�°� ���۹��� ���� ���ε�
    UPROPERTY(meta = (BindWidget))
    class UUserWidget* HealthBar;

    UPROPERTY(meta = (BindWidget))
    class UUserWidget* SuperMeterBar;

    // ��� ǥ�� ���� �迭 (BindWidget�� ���������� ����)
    UPROPERTY(meta = (BindWidget))
    class UUserWidget* LifeCounter1;

    UPROPERTY(meta = (BindWidget))
    class UUserWidget* LifeCounter2;

    UPROPERTY(meta = (BindWidget))
    class UUserWidget* LifeCounter3;


public:
    // ĳ���Ϳ��� �޾ƿ� Health �� ����
    float GetCurrentHealth() const;

    // ĳ���Ϳ��� �޾ƿ� ���۹��Ͱ� ����
    float GetCurrentSuperMeter() const;

    // ĳ���Ϳ��� �޾ƿ� ������� ����
    int32 GetRemainingLives() const; 

private:
    // ��� ǥ�� ���� �迭
   /* UPROPERTY(meta = (BindWidget))*/
    TArray<class UUserWidget*> LifeCounters;
};
