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

	UPROPERTY(EditAnywhere, Category = Spawn)
	class UClass *ActorClassToSpawn;
	
	UPROPERTY(EditAnywhere, Category = Spawn)
	int32 MaxActiveSpawns;

	UPROPERTY(EditAnywhere, Category = Spawn)
	float MinTimeBetweenSpawns;

	UPROPERTY(EditAnywhere, Category = Spawn)
	float MaxTimeBetweenSpawns;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool SpawnNew();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnSpawnedActorDestroyed(AActor *DestroyedActor);

private:
	void SetNewRandSpawnTime();
	void UpdateSpawn(float DeltaTime);

	TArray<TWeakObjectPtr<AActor>> ActiveSpawns;
	float mRandSpawnTime;
	float mTimeSinceLastSpawn;
};
