// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerScoreData.generated.h"

/**
 * 
 */
UCLASS()
class TESTTHIRDPERSON_API UPlayerScoreData : public UObject
{
	GENERATED_BODY()

public:
	UPlayerScoreData();

	UFUNCTION(BlueprintCallable, Category = "Player Score Data")
	void SetPlayerName(const FString &Name);
	UFUNCTION(BlueprintCallable, Category = "Player Score Data")
	void SetPlayerScore(int32 score);

	UFUNCTION(BlueprintCallable, Category = "Player Score Data")
	FString &GetPlayerName();
	UFUNCTION(BlueprintCallable, Category = "Player Score Data")
	int32 GetPlayerScore();
private:
	FString PlayerName;
	int32	PlayerScore;
};
