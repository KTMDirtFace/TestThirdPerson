// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DestructableProjectile.h"
#include "BoxProjectile.generated.h"

/**
 * 
 */
UCLASS()
class TESTTHIRDPERSON_API ABoxProjectile : public ADestructableProjectile
{
	GENERATED_BODY()
	
public:
	ABoxProjectile();

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UBoxComponent *BoxCollision;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent *VisualMesh;

private:

};
