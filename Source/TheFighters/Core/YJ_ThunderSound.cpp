#include "Core/YJ_ThunderSound.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"
#include "Engine/World.h"

// Sets default values
AYJ_ThunderSound::AYJ_ThunderSound()
{
    PrimaryActorTick.bCanEverTick = false;

    // ����� ������Ʈ ����
    AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
    RootComponent = AudioComponent;

    AudioComponent->bAutoActivate = false; // �ڵ� ��� ��
}

// Called when the game starts or when spawned
void AYJ_ThunderSound::BeginPlay()
{
    Super::BeginPlay();

    // ���� �迭 �ʱ�ȭ
    if (Thunder1) ThunderSounds.Add(Thunder1);
    if (Thunder2) ThunderSounds.Add(Thunder2);
    if (Thunder3) ThunderSounds.Add(Thunder3);

    if (ThunderSounds.Num() > 0)
    {
        PlayRandomThunder(); // ù ��� ����
    }
}

// ���� ���� ��� �Լ�
void AYJ_ThunderSound::PlayRandomThunder()
{
    if (ThunderSounds.Num() == 0) return;

    // ������ �ε��� ����Ʈ ����
    TArray<int32> AvailableIndexes;
    for (int32 i = 0; i < ThunderSounds.Num(); ++i)
    {
        if (i != LastPlayedIndex) // ���� �ε����� ����
        {
            AvailableIndexes.Add(i);
        }
    }

    // ���� �ϳ����̶�� ������ ��� (��� ���尡 ���� ��� ���)
    int32 SelectedIndex;
    if (AvailableIndexes.Num() > 0)
    {
        int32 RandomIdxInAvailable = FMath::RandRange(0, AvailableIndexes.Num() - 1);
        SelectedIndex = AvailableIndexes[RandomIdxInAvailable];
    }
    else
    {
        SelectedIndex = LastPlayedIndex; // fallback
    }

    USoundBase* SelectedSound = ThunderSounds[SelectedIndex];

    if (SelectedSound && AudioComponent)
    {
        AudioComponent->SetSound(SelectedSound);
        AudioComponent->Play();

        LastPlayedIndex = SelectedIndex; // ���� �ε��� ������Ʈ

        float Duration = SelectedSound->GetDuration();

        // ���� ��� ���� //
        GetWorld()->GetTimerManager().SetTimer(
            ThunderTimerHandle, this, &AYJ_ThunderSound::PlayRandomThunder, false);
    }
}