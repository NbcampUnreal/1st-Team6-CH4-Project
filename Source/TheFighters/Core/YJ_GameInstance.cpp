#include "Core/YJ_GameInstance.h"

#include "TheFighters.h"

UYJ_GameInstance::UYJ_GameInstance()
{
}

void UYJ_GameInstance::Init()
{
	Super::Init();

	InitAllGameResultData();
}

void UYJ_GameInstance::InitAllGameResultData()
{
	GameResultDataList.Init(FGameResultData(), TotalPlayerCount);
}

void UYJ_GameInstance::ReceiveGameResultData(int32 PlayerIndex, const FGameResultData& InResultData)
{
	if (IsValidPlayerIndex(PlayerIndex) == false)
	{
		YJ_LOG(Warning, TEXT("Player Index Out of Range"));
		return;
	}

	GameResultDataList[PlayerIndex] = InResultData;
}

const FGameResultData& UYJ_GameInstance::GetGameResultData(int32 PlayerIndex)
{
	/*if (PlayerIndex < 0 || PlayerIndex >= TotalPlayerCount)
	{
		YJ_LOG(Warning, TEXT("Player Index Out of Range"));
		return;
	}*/

	ensure(PlayerIndex >= 0 && PlayerIndex < TotalPlayerCount);
	return GameResultDataList[PlayerIndex];
}

const TArray<FGameResultData>& UYJ_GameInstance::GetAllGameResultDataList()
{
	return GameResultDataList;
}

void UYJ_GameInstance::AddTotalReceivedDamage(int32 PlayerIndex, int32 Amount)
{
	SetTotalReceivedDamage(PlayerIndex, GetGameResultData(PlayerIndex).TotalReceivedDamage + Amount);
}

void UYJ_GameInstance::AddAppliedDamage(int32 PlayerIndex, int32 Amount)
{
	SetAppliedDamage(PlayerIndex, GetGameResultData(PlayerIndex).AppliedDamage + Amount);
}

void UYJ_GameInstance::SetTotalReceivedDamage(int32 PlayerIndex, int32 Amount)
{
	if (IsValidPlayerIndex(PlayerIndex) == false)
	{
		YJ_LOG(Warning, TEXT("Player Index Out of Range"));
		return;
	}

	GameResultDataList[PlayerIndex].TotalReceivedDamage = Amount;
}

void UYJ_GameInstance::SetAppliedDamage(int32 PlayerIndex, int32 Amount)
{
	if (IsValidPlayerIndex(PlayerIndex) == false)
	{
		YJ_LOG(Warning, TEXT("Player Index Out of Range"));
		return;
	}

	GameResultDataList[PlayerIndex].AppliedDamage = Amount;
}

bool UYJ_GameInstance::IsValidPlayerIndex(int32 PlayerIndex)
{
	if (PlayerIndex < 0 || PlayerIndex >= TotalPlayerCount)
	{
		YJ_LOG(Warning, TEXT("Player Index Out of Range"));
		return false;
	}

	return true;
}
