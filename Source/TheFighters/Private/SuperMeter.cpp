


#include "SuperMeter.h"
#include "Components/ProgressBar.h"

void USuperMeter::NativeConstruct()
{
	Super::NativeConstruct();

	// 초기화 작업 필요 시 여기에 추가 가능
}


void USuperMeter::UpdateSuperMeter(float CurrentSuperMeter)
{
	if (SuperMeterProgressBar)
	{
		SuperMeterProgressBar->SetPercent(CurrentSuperMeter); // 슈퍼미터 값을 0~1 사이로 설정
	}
}

