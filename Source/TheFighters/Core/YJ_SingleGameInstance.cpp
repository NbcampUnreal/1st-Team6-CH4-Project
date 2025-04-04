#include "Core/YJ_SingleGameInstance.h"

//void UYJ_SingleGameInstance::SetSelectedCharacter(TSubclassOf<ABaseFighterCharacter> InClass)
//{
//	SelectedCharacterClass = InClass;
//}

void UYJ_SingleGameInstance::ApplyRoundStats(const AYJ_SingleGameState* RoundStats)
{
	if (!RoundStats) return;

	TotalDamageDealt += RoundStats->DamageDealt;
	TotalKO += RoundStats->KOCount;
	TotalDeaths += RoundStats->DeathCount;
	TotalKills += RoundStats->KillCount;
}