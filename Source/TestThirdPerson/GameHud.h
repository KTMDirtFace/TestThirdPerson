// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHud.generated.h"

/**
 * 
 */
UCLASS()
class TESTTHIRDPERSON_API AGameHud : public AHUD
{
	GENERATED_BODY()
	
public:
	/** Class for the main HUD widget */
	UPROPERTY(EditDefaultsOnly, Category = "Hud Widget")
	class UClass *GameHudWidgetClass;

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:

	class UGameHudWidget *GameHUDWidget;
};
