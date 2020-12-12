// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TestThirdPersonGameMode.h"
#include "TestThirdPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/PlayerState.h"

ATestThirdPersonGameMode::ATestThirdPersonGameMode()
{
/*
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
*/
}

void ATestThirdPersonGameMode::IncreaseScore(APawn *PlayerPawn)
{
	// Only the server is allowed to change the score.
	if (GetLocalRole() == ROLE_Authority)
	{
		if (PlayerPawn)
		{
			APlayerState *PlayerState = PlayerPawn->GetPlayerState();
			if (PlayerState)
			{
				PlayerState->Score += 1;
			}
		}
	}
}
