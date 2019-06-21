// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "UObject/NoExportTypes.h"
#include "PlayerScoreData.generated.h"

/**
 * 
 */
//UCLASS()
//class TESTTHIRDPERSON_API UPlayerScoreData : public UObject
USTRUCT(BlueprintType)
struct FPlayerScoreData
{
	GENERATED_BODY()

	FPlayerScoreData();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32	PlayerScore;
};
