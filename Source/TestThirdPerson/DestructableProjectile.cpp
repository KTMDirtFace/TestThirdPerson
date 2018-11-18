// Fill out your copyright notice in the Description page of Project Settings.

#include "DestructableProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ADestructableProjectile::ADestructableProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	//RootComponent = CollisionComponent;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(BoxCollision);

	//DestructionParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("DestructionParticle"));
	//DestructionParticle->SetupAttachment(VisualMesh);

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

