#pragma once

#include "CoreMinimal.h"
#include "Core/YJ_GameState.h"
#include "YJ_SingleGameState.generated.h"

UCLASS()
class THEFIGHTERS_API AYJ_SingleGameState : public AYJ_GameState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	int32 CurrentRoundScore;

	UPROPERTY(BlueprintReadOnly)
	bool bIsBossBattle;

	UFUNCTION(BlueprintCallable)
	void ResetRoundScore();

	UFUNCTION(BlueprintCallable)
	void SetBossBattle(bool bBoss);

	UPROPERTY(BlueprintReadWrite)
	int32 DamageDealt = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 KOCount = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 DeathCount = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 KillCount = 0;

	// 리셋 함수
	UFUNCTION(BlueprintCallable)
	void ResetBattleStats();
};
