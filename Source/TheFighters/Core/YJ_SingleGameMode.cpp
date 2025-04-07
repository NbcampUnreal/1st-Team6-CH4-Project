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
	// ĳ���� ����Ʈ UI�ϼ� ���� ĳ���� ����Ʈ�� �Ϸ��ϸ� �������Ʈ�� ���ε����� AdvanceGameState()���� ȣ��
	// ���� �����ܰ�(�ƽ�)���� �Ѿ��
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
	UE_LOG(LogTemp, Warning, TEXT("CharacterSelect state entered - UI �غ� �� ���⿡�� CreateWidget ȣ�� ����"));
}

void AYJ_SingleGameMode::HandleCutscene()
{
	// �ƽ� ����
	
	// �ƽ��� ������:
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
	// ���� ���������� ��ȯ (�ӽ� �̸�)
	UGameplayStatics::OpenLevel(this, "TestNormalLevel");

	// ���� ���� �� ��� ó��
	NormalBattleCount++;
	CurrentState = EStoryGameState::ScoreScreen;
	AdvanceGameState();
}

void AYJ_SingleGameMode::HandleScoreScreen()
{
	// ���� ȭ�� ������ �� �ƽ�����
	CurrentState = EStoryGameState::Cutscene;
	AdvanceGameState();
}

void AYJ_SingleGameMode::HandleBossBattle()
{
	UGameplayStatics::OpenLevel(this, "TestBossLevel");
	// ������ ó��
	CurrentState = EStoryGameState::Ending;
	AdvanceGameState();
}

void AYJ_SingleGameMode::HandleEnding()
{
	// ���� �ƽ�
	CurrentState = EStoryGameState::ReturnToMenu;
	AdvanceGameState();
}

