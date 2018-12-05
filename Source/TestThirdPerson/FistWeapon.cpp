// Fill out your copyright notice in the Description page of Project Settings.

#include "FistWeapon.h"

#include "BorisCharacter.h"
#include "DestructableProjectile.h"
#include "Components/SphereComponent.h"
#include "SpawnGenerator.h"

PRAGMA_DISABLE_OPTIMIZATION

AFistWeapon::AFistWeapon()
{
	WeaponCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("WeaponCollisionSphere"));
	RootComponent = WeaponCollisionSphere;

	WeaponCollisionSphere->SetSphereRadius(60.0f);
}

void AFistWeapon::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	// Only the server is allowed to determine if this weapon should destroy the object.
	if (Role == ROLE_Authority)
	{
		if (OtherActor && OtherActor->IsA<ADestructableProjectile>())
		{
			ASpawnGenerator *OwnerAsGenerator = Cast<ASpawnGenerator>(OtherActor->GetOwner());
			if (OwnerAsGenerator)
			{
				OwnerAsGenerator->OnSpawnedActorDestroyed(OtherActor);

				// Temp testing
				ABorisCharacter *BorisChar = Cast<ABorisCharacter>(GetOwner());
				if (BorisChar)
				{
					BorisChar->TestScore++;
				}
			}

			OtherActor->Destroy();
		}
	}
}

PRAGMA_ENABLE_OPTIMIZATION