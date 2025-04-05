#include "Core/YJ_GameState.h"

#include "Net/UnrealNetwork.h"

void AYJ_GameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AYJ_GameState, GameResultDataList);
}

const TArray<FGameResultData>& AYJ_GameState::GetGameResultData() const
{
	return GameResultDataList;
}

void AYJ_GameState::SetGameResultData(const TArray<FGameResultData>& NewGameResultDataList)
{
	GameResultDataList = NewGameResultDataList;
}

void AYJ_GameState::OnRep_GameResultDataList()
{
	OnGameResultDataListReplicatedDelegate.Broadcast();
}
