#include "Core/YJ_GameMode.h"

#include "TheFighters.h"
void AYJ_GameMode::TestCPUMatch()
{
	FName FunctionName = FName(TEXT("StartCPUMatch"));
	UFunction* CpuMatchFunction = FindFunction(FunctionName);

	if (CpuMatchFunction == nullptr)
	{
		YJ_LOG(Error, TEXT("CpuMatchFunction == nullptr"));
		return;
	}

	ProcessEvent(CpuMatchFunction, nullptr);
}
