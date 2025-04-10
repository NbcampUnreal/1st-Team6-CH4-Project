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

void AYJ_GameMode::SwitchTeamMode()
{
	FName FunctionName = FName(TEXT("SwitchTeamModeEvent"));
	UFunction* SwitchTeamModeFunction = FindFunction(FunctionName);

	if (SwitchTeamModeFunction == nullptr)
	{
		YJ_LOG(Error, TEXT("SwitchTeamModeFunction == nullptr"));
		return;
	}

	ProcessEvent(SwitchTeamModeFunction, nullptr);
}
