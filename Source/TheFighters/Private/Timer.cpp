


#include "Timer.h"
#include "Components/TextBlock.h"

void UTimer::NativeConstruct()
{
	Super::NativeConstruct();

	// �ʱ�ȭ �۾� �ʿ� �� ���⿡ �߰� ����
}

void UTimer::UpdateTimer(float RemainingTime)
{
	if (TimerText)
	{
		TimerText->SetText(FText::AsNumber(FMath::RoundToInt(RemainingTime))); // ���� �ð��� ǥ��
	}
}

