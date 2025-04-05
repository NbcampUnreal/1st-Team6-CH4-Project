#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintPlatformLibrary.h"

#include "YJ_GameInstance.generated.h"

USTRUCT(BlueprintType)
struct FGameResultData
{
	GENERATED_BODY();

	FGameResultData(){}
	FGameResultData(int32 NewTotalReceivedDamage, int32 NewAppliedDamage)
	{
		TotalReceivedDamage = NewTotalReceivedDamage;
		AppliedDamage = NewAppliedDamage;
	}

	UPROPERTY(BlueprintReadOnly)
	int32 TotalReceivedDamage = 0;

	UPROPERTY(BlueprintReadOnly)
	int32 AppliedDamage = 0;

	void operator = (const FGameResultData& Other)
	{
		TotalReceivedDamage = Other.TotalReceivedDamage;
		AppliedDamage = Other.AppliedDamage;
	}
};
/**
 * 
 */
UCLASS()
class THEFIGHTERS_API UYJ_GameInstance : public UPlatformGameInstance
{
	GENERATED_BODY()

public:

	UYJ_GameInstance();

protected:

	virtual void Init() override;

public:

	UFUNCTION(BlueprintCallable, Category = "YJGameInstance")
	void InitAllGameResultData();

	UFUNCTION(BlueprintCallable, Category = "YJGameInstance")
	void ReceiveGameResultData(int32 PlayerIndex, const FGameResultData& InResultData);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "YJGameInstance")
	const FGameResultData& GetGameResultData(int32 PlayerIndex);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "YJGameInstance")
	const TArray<FGameResultData>& GetAllGameResultDataList();

	UFUNCTION(BlueprintCallable, Category = "YJGameInstance")
	void AddTotalReceivedDamage(int32 PlayerIndex, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "YJGameInstance")
	void AddAppliedDamage(int32 PlayerIndex, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "YJGameInstance")
	void SetTotalReceivedDamage(int32 PlayerIndex, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "YJGameInstance")
	void SetAppliedDamage(int32 PlayerIndex, int32 Amount);


private:

	bool IsValidPlayerIndex(int32 PlayerIndex);

protected:

	// 플레이어 인덱스를 배열 인덱스로 받음
	TArray<FGameResultData> GameResultDataList;

	const int32 TotalPlayerCount = 4;
};
