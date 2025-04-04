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
	// ĳ���� Ŭ���� or ID ����
	//UPROPERTY(BlueprintReadWrite)
	//TSubclassOf<class ABaseFighterCharacter> SelectedCharacterClass;

	// �� ���� ����
	UPROPERTY(BlueprintReadWrite)
	int32 TotalScore;

	// ���丮 ���� ���� ī��Ʈ
	UPROPERTY(BlueprintReadWrite)
	int32 BattleCount;

	// ���� �Ϸ� �� �Ҹ��� �Լ�
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
 