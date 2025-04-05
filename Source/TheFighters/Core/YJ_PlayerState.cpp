#include "Core/YJ_PlayerState.h"

#include "Net/UnrealNetwork.h"

AYJ_PlayerState::AYJ_PlayerState()
{

}

void AYJ_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	/*DOREPLIFETIME(AYJ_PlayerState, TotalReceivedDamage);
	DOREPLIFETIME(AYJ_PlayerState, AppliedDamage);*/
	//DOREPLIFETIME(AYJ_PlayerState, GameResultData);
}

//void AYJ_PlayerState::AddToTotalReceivedDamage(int32 Amount)
//{
//	SetTotalReceivedDamage(TotalReceivedDamage + Amount);
//}
//
//void AYJ_PlayerState::SetTotalReceivedDamage(int32 Amount)
//{
//	TotalReceivedDamage = Amount;
//
//	if (HasAuthority())
//	{
//		OnRep_TotalReceivedDamage();
//	}
//}
//
//int32 AYJ_PlayerState::GetTotalReceivedDamage() const
//{
//	return TotalReceivedDamage;
//}
//
//void AYJ_PlayerState::AddToAppliedDamage(int32 Amount)
//{
//	SetAppliedDamage(AppliedDamage + Amount);
//}
//
//void AYJ_PlayerState::SetAppliedDamage(int32 Amount)
//{
//	AppliedDamage = Amount;
//
//	if (HasAuthority())
//	{
//		OnRep_AppliedDamage();
//	}
//}
//
//int32 AYJ_PlayerState::GetAppliedDamage() const
//{
//	return AppliedDamage;
//}

//const FGameResultData& AYJ_PlayerState::GetGameResultData() const
//{
//	return GameResultData;
//}
//
//void AYJ_PlayerState::SetGameResultData(const FGameResultData& NewGameResultData)
//{
//	GameResultData = NewGameResultData;
//
//	if (HasAuthority())
//	{
//		OnRep_GameResultData();
//	}
//}

//void AYJ_PlayerState::OnRep_TotalReceivedDamage()
//{
//	OnTotalReceivedDamageReplicatedDelegate.Broadcast(TotalReceivedDamage);
//}
//
//void AYJ_PlayerState::OnRep_AppliedDamage()
//{
//	OnAppliedDamageReplicatedDelegate.Broadcast(AppliedDamage);
//}

//void AYJ_PlayerState::OnRep_GameResultData()
//{
//	OnGameResultDataReplicatedDelegate.Broadcast(GameResultData);
//}
