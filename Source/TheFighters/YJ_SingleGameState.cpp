#include "YJ_SingleGameState.h"

void AYJ_SingleGameState::ResetRoundScore()
{
	CurrentRoundScore = 0;
}

void AYJ_SingleGameState::SetBossBattle(bool bBoss)
{
	bIsBossBattle = bBoss;
}

void AYJ_SingleGameState::ResetBattleStats()
{
	DamageDealt = 0;
	KOCount = 0;
	DeathCount = 0;
	KillCount = 0;
}