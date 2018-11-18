// Fill out your copyright notice in the Description page of Project Settings.

#include "FistWeapon.h"

#include "DestructableProjectile.h"
#include "Components/SphereComponent.h"

AFistWeapon::AFistWeapon()
{
	WeaponCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("WeaponCollisionSphere"));
	RootComponent = WeaponCollisionSphere;

	WeaponCollisionSphere->SetSphereRadius(60.0f);
}

void AFistWeapon::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (OtherActor && OtherActor->IsA<ADestructableProjectile>())
	{
		OtherActor->Destroy();
	}
}