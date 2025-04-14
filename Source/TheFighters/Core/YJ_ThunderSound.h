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

    // ���� ���� ��� �Լ�
    void PlayRandomThunder();

    // Ÿ�̸� �ڵ�
    FTimerHandle ThunderTimerHandle;

    // ���� ��� ������Ʈ
    UPROPERTY(VisibleAnywhere)
    UAudioComponent* AudioComponent;

    // õ�� ���� ���
    UPROPERTY(EditAnywhere, Category = "Thunder Sound")
    USoundBase* Thunder1;

    UPROPERTY(EditAnywhere, Category = "Thunder Sound")
    USoundBase* Thunder2;

    UPROPERTY(EditAnywhere, Category = "Thunder Sound")
    USoundBase* Thunder3;

    // ���� �迭
    TArray<USoundBase*> ThunderSounds;

    // ���������� ����� ���� �ε����� ����
    int32 LastPlayedIndex = -1;
};
