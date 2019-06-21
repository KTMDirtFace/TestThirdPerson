// Fill out your copyright notice in the Description page of Project Settings.

#include "GameHud.h"
#include "GameHudWidget.h"

void AGameHud::BeginPlay()
{
	Super::BeginPlay();

	GameHUDWidget = CreateWidget<UGameHudWidget>(GetWorld(), GameHudWidgetClass);
	
	if (GameHUDWidget != nullptr)
	{
		GameHUDWidget->AddToViewport();
	}
}

void AGameHud::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}