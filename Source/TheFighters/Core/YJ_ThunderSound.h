#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YJ_ThunderSound.generated.h"

UCLASS()
class THEFIGHTERS_API AYJ_ThunderSound : public AActor
{
	GENERATED_BODY()
	
public:	
	AYJ_ThunderSound();

protected:
	virtual void BeginPlay() override;

    // 랜덤 사운드 재생 함수
    void PlayRandomThunder();

    // 타이머 핸들
    FTimerHandle ThunderTimerHandle;

    // 사운드 재생 컴포넌트
    UPROPERTY(VisibleAnywhere)
    UAudioComponent* AudioComponent;

    // 천둥 사운드 목록
    UPROPERTY(EditAnywhere, Category = "Thunder Sound")
    USoundBase* Thunder1;

    UPROPERTY(EditAnywhere, Category = "Thunder Sound")
    USoundBase* Thunder2;

    UPROPERTY(EditAnywhere, Category = "Thunder Sound")
    USoundBase* Thunder3;

    // 사운드 배열
    TArray<USoundBase*> ThunderSounds;

    // 마지막으로 재생된 사운드 인덱스를 저장
    int32 LastPlayedIndex = -1;
};
