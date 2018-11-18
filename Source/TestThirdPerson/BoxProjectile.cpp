// Fill out your copyright notice in the Description page of Project Settings.

#include "BoxProjectile.h"

#include "Components/BoxComponent.h"

ABoxProjectile::ABoxProjectile()
{
	// Setup Box Collision
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(BoxCollision);
}