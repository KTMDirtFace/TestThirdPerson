// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerScoreData.h"
#include "GameHudWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTTHIRDPERSON_API UGameHudWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	void UpdatePlayerScoreData();

	TArray<FPlayerScoreData> PlayerScoreDataList;
};
