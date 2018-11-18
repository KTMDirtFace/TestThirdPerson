// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnGenerator.h"

// Sets default values
ASpawnGenerator::ASpawnGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

