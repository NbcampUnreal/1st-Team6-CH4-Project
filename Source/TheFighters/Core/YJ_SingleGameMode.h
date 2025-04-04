#pragma once

#include "CoreMinimal.h"
#include "Core/YJ_GameMode.h"
#include "YJ_SingleGameMode.generated.h"

UENUM(BlueprintType)
enum class EStoryGameState : uint8
{
	CharacterSelect,
	Cutscene,
	NormalBattle,
	ScoreScreen,
	BossBattle,
	Ending,
	ReturnToMenu
};

UCLASS()
class THEFIGHTERS_API AYJ_SingleGameMode : public AYJ_GameMode
{
	GENERATED_BODY()

public:
	AYJ_SingleGameMode();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void AdvanceGameState();

protected:
	void HandleCharacterSelect();
	void HandleCutscene();
	void HandleNormalBattle();
	void HandleBossBattle();
	void HandleScoreScreen();
	void HandleEnding();

	UPROPERTY(BlueprintReadWrite, Category = "StoryState")
	EStoryGameState CurrentState;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> CharacterSelectWidgetClass;

	int32 NormalBattleCount;
};
