


#include "SuperMeter.h"
#include "Components/ProgressBar.h"

void USuperMeter::NativeConstruct()
{
	Super::NativeConstruct();

	// �ʱ�ȭ �۾� �ʿ� �� ���⿡ �߰� ����
}


void USuperMeter::UpdateSuperMeter(float CurrentSuperMeter)
{
	if (SuperMeterProgressBar)
	{
		SuperMeterProgressBar->SetPercent(CurrentSuperMeter); // ���۹��� ���� 0~1 ���̷� ����
	}
}

