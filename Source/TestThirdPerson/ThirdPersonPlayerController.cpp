// Fill out your copyright notice in the Description page of Project Settings.

#include "ThirdPersonPlayerController.h"

AThirdPersonPlayerController::AThirdPersonPlayerController()
{
	bInvertLook = true;
}

void AThirdPersonPlayerController::AddPitchInput(float Val)
{
	Val = bInvertLook ? -Val : Val;

	Super::AddPitchInput(Val);
}