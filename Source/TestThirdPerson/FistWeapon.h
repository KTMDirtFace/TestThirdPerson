// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "FistWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TESTTHIRDPERSON_API AFistWeapon : public AWeaponBase
{
	GENERATED_BODY()
	
public:
	AFistWeapon();

	/** Collision sphere for the right hand */
	UPROPERTY(VisibleAnywhere, Category="Fist Collision")
	class USphereComponent *WeaponCollisionSphere;

public:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
private:

};
