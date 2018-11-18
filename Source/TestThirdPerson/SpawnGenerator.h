// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnGenerator.generated.h"

UCLASS()
class TESTTHIRDPERSON_API ASpawnGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnGenerator();

	UPROPERTY(EditDefaultsOnly, Category = Spawn)
	class UClass *ActorClassToSpawn;
	
	UPROPERTY(EditDefaultsOnly, Category = Spawn)
	int32 MaxActiveSpawns;

	UPROPERTY(EditDefaultsOnly, Category = Spawn)
	float MinTimeBetweenSpawns;

	UPROPERTY(EditDefaultsOnly, Category = Spawn)
	float MaxTimeBetweenSpawns;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool SpawnNew();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnSpawnedActorDestroyed(AActor *DestroyedActor);

	void SetNewRandSpawnTime();
	void UpdateSpawn(float DeltaTime);

	TArray<TWeakObjectPtr<AActor>> ActiveSpawns;
	float mRandSpawnTime;
	float mTimeSinceLastSpawn;
};
