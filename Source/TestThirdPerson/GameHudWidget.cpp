// Fill out your copyright notice in the Description page of Project Settings.

#include "GameHudWidget.h"
#include "TestThirdPersonGameMode.h"
#include "Runtime/Engine/Classes/GameFramework/GameStateBase.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerState.h"

void UGameHudWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UpdatePlayerScoreData();
}

void UGameHudWidget::UpdatePlayerScoreData()
{
	PlayerScoreDataList.Reset();

	ATestThirdPersonGameMode* const GameMode = Cast<ATestThirdPersonGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		AGameStateBase* GameState = GameMode->GameState;
		if (GameState)
		{
			for (int32 i = 0; i < GameState->PlayerArray.Num(); ++i)
			{
				APlayerState *PlayerState = GameState->PlayerArray[i];

				FPlayerScoreData ScoreData;
				ScoreData.PlayerName = PlayerState->GetPlayerName();
				ScoreData.PlayerScore = PlayerState->Score;

				PlayerScoreDataList.Push(ScoreData);
			}
		}
	}
}