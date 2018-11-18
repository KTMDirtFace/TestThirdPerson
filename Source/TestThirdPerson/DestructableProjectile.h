// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestructableProjectile.generated.h"

UCLASS()
class TESTTHIRDPERSON_API ADestructableProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestructableProjectile();

	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
	class USoundBase *DestructionAudio;

	UPROPERTY(EditDefaultsOnly, Category = "Particles")
	class UParticleSystem *DestructionParticle;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UProjectileMovementComponent *ProjectileMovementComponent;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;

private:

};
