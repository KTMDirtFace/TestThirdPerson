// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ThirdPersonPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TESTTHIRDPERSON_API AThirdPersonPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AThirdPersonPlayerController();

	virtual void AddPitchInput(float Val) override;

	UPROPERTY(EditAnywhere, Category = "Control Settings")
	bool bInvertLook;
};
