


#include "Timer.h"
#include "Components/TextBlock.h"

void UTimer::NativeConstruct()
{
	Super::NativeConstruct();

	// 초기화 작업 필요 시 여기에 추가 가능
}

void UTimer::UpdateTimer(float RemainingTime)
{
	if (TimerText)
	{
		TimerText->SetText(FText::AsNumber(FMath::RoundToInt(RemainingTime))); // 남은 시간을 표시
	}
}

