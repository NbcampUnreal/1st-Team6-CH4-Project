#include "Core/YJ_SingleGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h" 

AYJ_SingleGameMode::AYJ_SingleGameMode()
{
	CurrentState = EStoryGameState::CharacterSelect;
	NormalBattleCount = 0;
}

void AYJ_SingleGameMode::BeginPlay()
{
	Super::BeginPlay();
	AdvanceGameState();
}

void AYJ_SingleGameMode::AdvanceGameState()
{
	switch (CurrentState)
	{
	case EStoryGameState::CharacterSelect:
		HandleCharacterSelect();
		break;

	case EStoryGameState::Cutscene:
		HandleCutscene();
		break;

	case EStoryGameState::NormalBattle:
		HandleNormalBattle();
		break;

	case EStoryGameState::BossBattle:
		HandleBossBattle();
		break;

	case EStoryGameState::ScoreScreen:
		HandleScoreScreen();
		break;

	case EStoryGameState::Ending:
		HandleEnding();
		break;

	case EStoryGameState::ReturnToMenu:
		UGameplayStatics::OpenLevel(this, "MainMenu");
		break;
	}
}

void AYJ_SingleGameMode::HandleCharacterSelect()
{
	// ShowCharacterSelectWidget();
	// 캐릭터 셀렉트 UI완성 이후 캐릭터 셀렉트를 완료하면 블루프린트나 바인딩에서 AdvanceGameState()수동 호출
	// 이후 다음단계(컷신)으로 넘어가기
	if (CharacterSelectWidgetClass)
	{
		UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), CharacterSelectWidgetClass);
		if (Widget)
		{
			Widget->AddToViewport();

			APlayerController* PC = GetWorld()->GetFirstPlayerController();
			if (PC)
			{
				FInputModeUIOnly InputMode;
				InputMode.SetWidgetToFocus(Widget->TakeWidget());
				PC->SetInputMode(InputMode);
				PC->bShowMouseCursor = true;
			}
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("CharacterSelect state entered - UI 준비 시 여기에서 CreateWidget 호출 예정"));
}

void AYJ_SingleGameMode::HandleCutscene()
{
	// 컷신 시작
	
	// 컷신이 끝나면:
	if (NormalBattleCount < 3)
	{
		CurrentState = EStoryGameState::NormalBattle;
	}
	else
	{
		CurrentState = EStoryGameState::BossBattle;
	}
	AdvanceGameState();
}

void AYJ_SingleGameMode::HandleNormalBattle()
{
	// 전투 스테이지로 전환 (임시 이름)
	UGameplayStatics::OpenLevel(this, "TestNormalLevel");

	// 전투 시작 후 결과 처리
	NormalBattleCount++;
	CurrentState = EStoryGameState::ScoreScreen;
	AdvanceGameState();
}

void AYJ_SingleGameMode::HandleScoreScreen()
{
	// 점수 화면 보여준 후 컷신으로
	CurrentState = EStoryGameState::Cutscene;
	AdvanceGameState();
}

void AYJ_SingleGameMode::HandleBossBattle()
{
	UGameplayStatics::OpenLevel(this, "TestBossLevel");
	// 보스전 처리
	CurrentState = EStoryGameState::Ending;
	AdvanceGameState();
}

void AYJ_SingleGameMode::HandleEnding()
{
	// 엔딩 컷신
	CurrentState = EStoryGameState::ReturnToMenu;
	AdvanceGameState();
}

