// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnGenerator.h"

// Sets default values
ASpawnGenerator::ASpawnGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MaxActiveSpawns = 3;
	MinTimeBetweenSpawns = 0.5f;
	MaxTimeBetweenSpawns = 3.0f;
	mTimeSinceLastSpawn = 0.0f;
}

// Called when the game starts or when spawned
void ASpawnGenerator::BeginPlay()
{
	Super::BeginPlay();
	
	SetNewRandSpawnTime();
}

bool ASpawnGenerator::SpawnNew()
{
	bool bSpawned = false;
	
	FTransform SpawnTransform = GetActorTransform();
	AActor *SpawnedActor = GetWorld()->SpawnActor(ActorClassToSpawn, &SpawnTransform);

	if (SpawnedActor != nullptr)
	{
		bSpawned = true;
		mTimeSinceLastSpawn = 0.0f;
		SetNewRandSpawnTime();

		ActiveSpawns.Add(SpawnedActor);
		SpawnedActor->OnDestroyed.AddDynamic(this, &ASpawnGenerator::OnSpawnedActorDestroyed);
	}

	return bSpawned;
}

// Called every frame
void ASpawnGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateSpawn(DeltaTime);
}

void ASpawnGenerator::OnSpawnedActorDestroyed(AActor *DestroyedActor)
{
	ActiveSpawns.Remove(DestroyedActor);
}

void ASpawnGenerator::SetNewRandSpawnTime()
{
	mRandSpawnTime = FMath::FRandRange(MinTimeBetweenSpawns, MaxTimeBetweenSpawns);
}

void ASpawnGenerator::UpdateSpawn(float DeltaTime)
{
	mTimeSinceLastSpawn += DeltaTime;

	if (mTimeSinceLastSpawn > mRandSpawnTime)
	{
		if (ActiveSpawns.Num() < MaxActiveSpawns)
		{
			SpawnNew();
		}
	}
}

