// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerScoreData.h"

UPlayerScoreData::UPlayerScoreData()
{
	PlayerName = "DummyText";
	PlayerScore = 0;
}

void UPlayerScoreData::SetPlayerName(const FString &Name)
{
	PlayerName = Name;
}

void UPlayerScoreData::SetPlayerScore(int32 score)
{
	PlayerScore = score;
}

FString &UPlayerScoreData::GetPlayerName()
{
	return PlayerName;
}

int32 UPlayerScoreData::GetPlayerScore()
{
	return PlayerScore;
}