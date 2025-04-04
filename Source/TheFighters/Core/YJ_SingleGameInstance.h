#pragma once

#include "CoreMinimal.h"
#include "Core/YJ_GameInstance.h"
#include "YJ_SingleGameState.h"
#include "YJ_SingleGameInstance.generated.h"

UCLASS()
class THEFIGHTERS_API UYJ_SingleGameInstance : public UYJ_GameInstance
{
	GENERATED_BODY()

public:
	// 캐릭터 클래스 or ID 저장
	//UPROPERTY(BlueprintReadWrite)
	//TSubclassOf<class ABaseFighterCharacter> SelectedCharacterClass;

	// 총 누적 점수
	UPROPERTY(BlueprintReadWrite)
	int32 TotalScore;

	// 스토리 전투 진행 카운트
	UPROPERTY(BlueprintReadWrite)
	int32 BattleCount;

	// 선택 완료 시 불리는 함수
	//UFUNCTION(BlueprintCallable)
	//void SetSelectedCharacter(TSubclassOf<ABaseFighterCharacter> InClass);
	
	UPROPERTY(BlueprintReadWrite)
	int32 TotalDamageDealt = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 TotalKO = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 TotalDeaths = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 TotalKills = 0;

	UFUNCTION(BlueprintCallable)
	void ApplyRoundStats(const AYJ_SingleGameState* RoundStats);
};
 