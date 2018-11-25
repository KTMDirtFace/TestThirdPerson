// Fill out your copyright notice in the Description page of Project Settings.

#include "DestructableProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ADestructableProjectile::ADestructableProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set this actor to replicate
	SetReplicates(true);
	SetReplicateMovement(true);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));

}

// Called when the game starts or when spawned
void ADestructableProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestructableProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADestructableProjectile::Destroyed()
{
	// Don't need to spawn the particles or sound on a dedicated server.
	if (!IsRunningDedicatedServer())
	{
		if (DestructionParticle)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DestructionParticle, GetActorTransform());
		}

		if (DestructionAudio)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), DestructionAudio, GetActorLocation());
		}
	}
}
