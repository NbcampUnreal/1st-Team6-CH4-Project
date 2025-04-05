#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"

#include "Core/YJ_GameInstance.h"

#include "YJ_GameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameResultDataListReplicatedDelegate);

/**
 * 
 */
UCLASS()
class THEFIGHTERS_API AYJ_GameState : public AGameStateBase
{
	GENERATED_BODY()
	

protected:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:

	UPROPERTY(BlueprintAssignable)
	FOnGameResultDataListReplicatedDelegate OnGameResultDataListReplicatedDelegate;

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "YJPlayerState")
	const TArray<FGameResultData>& GetGameResultData() const;

	UFUNCTION(BlueprintCallable, Category = "YJPlayerState")
	void SetGameResultData(const TArray<FGameResultData>& NewGameResultDataList);

private:

	UFUNCTION()
	void OnRep_GameResultDataList();

private:

	UPROPERTY(ReplicatedUsing = OnRep_GameResultDataList)
	TArray<FGameResultData> GameResultDataList;
};
