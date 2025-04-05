#pragma once

#include "CoreMinimal.h"

#define LOG_CALLINFO ANSI_TO_TCHAR(__FUNCTION__)
#define LOG_NETMODEINFO ((GetNetMode() == ENetMode::NM_Client) ? *FString::Printf(TEXT("CLIENT%d"), UE::GetPlayInEditorID()) : (GetNetMode() == ENetMode::NM_Standalone) ? TEXT("STANDALONE") : TEXT("SERVER"))
#define YJ_LOG_NET(Verbosity, Format, ...) UE_LOG(YJLOG, Verbosity, TEXT("[ %s ] %s(%s) %s"), LOG_NETMODEINFO, LOG_CALLINFO, *FString::FromInt(__LINE__), *FString::Printf(Format, ##__VA_ARGS__))
#define YJ_LOG(Verbosity, Format, ...) UE_LOG(YJLOG, Verbosity, TEXT("%s(%s) %s"), LOG_CALLINFO, *FString::FromInt(__LINE__), *FString::Printf(Format, ##__VA_ARGS__))

DECLARE_LOG_CATEGORY_EXTERN(YJLOG, Log, All);