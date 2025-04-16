

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
    // 현재 캐릭터의 초상화 설정하는 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetPlayerPortrait(UTexture2D* PortraitTexture);

    // 현재 캐릭터의 번호 설정하는 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetPlayerNumber(UTexture2D* PlayerNumberTexture);
    
public:
    // 체력 업데이트 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateHealth(float CurrentHealth);

    // 슈퍼미터 업데이트 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateSuperMeter(float CurrentSuperMeter);

    // 목숨 업데이트 함수
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateLives(int32 RemainingLives);


protected:
    virtual void NativeConstruct() override;

    // 현재 캐릭터의 초상화  
    UPROPERTY(meta = (BindWidget))
    class UImage* PlayerPortraitImage;


    // 현재 캐릭터의 플레이어번호 
    UPROPERTY(meta = (BindWidget))
    class UImage* PlayerNumberImage;


    // 체력과 슈퍼미터 위젯 바인딩
    UPROPERTY(meta = (BindWidget))
    class UUserWidget* HealthBar;

    UPROPERTY(meta = (BindWidget))
    class UUserWidget* SuperMeterBar;

    // 목숨 표시 위젯 배열 (BindWidget은 개별적으로 설정)
    UPROPERTY(meta = (BindWidget))
    class UUserWidget* LifeCounter1;

    UPROPERTY(meta = (BindWidget))
    class UUserWidget* LifeCounter2;

    UPROPERTY(meta = (BindWidget))
    class UUserWidget* LifeCounter3;


public:
    // 캐릭터에서 받아온 Health 값 리턴
    float GetCurrentHealth() const;

    // 캐릭터에서 받아온 슈퍼미터값 리턴
    float GetCurrentSuperMeter() const;

    // 캐릭터에서 받아온 목숨개수 리턴
    int32 GetRemainingLives() const; 

private:
    // 목숨 표시 위젯 배열
   /* UPROPERTY(meta = (BindWidget))*/
    TArray<class UUserWidget*> LifeCounters;
};
