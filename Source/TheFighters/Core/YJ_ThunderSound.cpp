#include "Core/YJ_ThunderSound.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"
#include "Engine/World.h"

// Sets default values
AYJ_ThunderSound::AYJ_ThunderSound()
{
    PrimaryActorTick.bCanEverTick = false;

    // 오디오 컴포넌트 생성
    AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
    RootComponent = AudioComponent;

    AudioComponent->bAutoActivate = false; // 자동 재생 끔
}

// Called when the game starts or when spawned
void AYJ_ThunderSound::BeginPlay()
{
    Super::BeginPlay();

    // 사운드 배열 초기화
    if (Thunder1) ThunderSounds.Add(Thunder1);
    if (Thunder2) ThunderSounds.Add(Thunder2);
    if (Thunder3) ThunderSounds.Add(Thunder3);

    if (ThunderSounds.Num() > 0)
    {
        PlayRandomThunder(); // 첫 재생 시작
    }
}

// 랜덤 사운드 재생 함수
void AYJ_ThunderSound::PlayRandomThunder()
{
    if (ThunderSounds.Num() == 0) return;

    // 가능한 인덱스 리스트 생성
    TArray<int32> AvailableIndexes;
    for (int32 i = 0; i < ThunderSounds.Num(); ++i)
    {
        if (i != LastPlayedIndex) // 이전 인덱스는 제외
        {
            AvailableIndexes.Add(i);
        }
    }

    // 만약 하나뿐이라면 강제로 사용 (모든 사운드가 같을 경우 대비)
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

        LastPlayedIndex = SelectedIndex; // 이전 인덱스 업데이트

        float Duration = SelectedSound->GetDuration();

        // 다음 재생 예약 //
        GetWorld()->GetTimerManager().SetTimer(
            ThunderTimerHandle, this, &AYJ_ThunderSound::PlayRandomThunder, false);
    }
}