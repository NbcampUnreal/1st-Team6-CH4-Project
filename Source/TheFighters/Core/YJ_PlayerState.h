#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "YJ_PlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCopyPropertiesDelegate, APlayerState*, OldPlayerState);
/**
 * 
 */
UCLASS()
class THEFIGHTERS_API AYJ_PlayerState : public APlayerState
{
	GENERATED_BODY()


public:

	AYJ_PlayerState();

protected:

	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void CopyProperties(APlayerState* PlayerState) override;

public:

	UPROPERTY(BlueprintAssignable, Category = "YJPlayerState")
	FOnCopyPropertiesDelegate OnCopyPropertiesDelegate;

public:

	UFUNCTION(BlueprintCallable, Category = "YJPlayerState")
	const FString GetId() const;
	/*UFUNCTION(BlueprintCallable, Category = "YJPlayerState")
	void AddToTotalReceivedDamage(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "YJPlayerState")
	void SetTotalReceivedDamage(int32 Amount);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "YJPlayerState")
	int32 GetTotalReceivedDamage() const;

	UFUNCTION(BlueprintCallable, Category = "YJPlayerState")
	void AddToAppliedDamage(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "YJPlayerState")
	void SetAppliedDamage(int32 Amount);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "YJPlayerState")
	int32 GetAppliedDamage() const;*/

	/*UFUNCTION(BlueprintCallable, BlueprintPure, Category = "YJPlayerState")
	const FGameResultData& GetGameResultData() const;

	UFUNCTION(BlueprintCallable, Category = "YJPlayerState")
	void SetGameResultData(const FGameResultData& NewGameResultData);*/

private:

	/*UFUNCTION()
	void OnRep_TotalReceivedDamage();

	UFUNCTION()
	void OnRep_AppliedDamage();*/

	/*UFUNCTION()
	void OnRep_GameResultData();*/

private:

	/*UPROPERTY(ReplicatedUsing = OnRep_TotalReceivedDamage)
	int32 TotalReceivedDamage = 0;

	UPROPERTY(ReplicatedUsing = OnRep_AppliedDamage)
	int32 AppliedDamage = 0;*/

	/*UPROPERTY(ReplicatedUsing = OnRep_GameResultData)
	FGameResultData GameResultData;*/

};
