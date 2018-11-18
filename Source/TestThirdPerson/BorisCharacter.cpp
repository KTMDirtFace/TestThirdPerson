// Fill out your copyright notice in the Description page of Project Settings.

#include "BorisCharacter.h"

#include "FistWeapon.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"

// Sets default values
ABorisCharacter::ABorisCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bIsPerformingMainAttack = false;
}

// Called when the game starts or when spawned
void ABorisCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// Add a fist collision weapon to Boris's right hand.
	RightFistWeapon = GetWorld()->SpawnActor<AFistWeapon>(RightFistWeaponClass);
	USkeletalMeshComponent *BorisMesh = GetMesh();
	if (BorisMesh && RightFistWeapon)
	{
		RightFistWeapon->AttachToComponent(BorisMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName("hand_r"));
		RightFistWeapon->SetActorEnableCollision(false);
	}
}

void ABorisCharacter::StartAttacking()
{
	if (!bIsPerformingMainAttack)
	{
		PlayAnimMontage(PrimaryAttack_A_Montage);
	}
}

// Called every frame
void ABorisCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABorisCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABorisCharacter::OnMainAttackSwingFinished()
{
	bIsPerformingMainAttack = false;

	if (RightFistWeapon)
		RightFistWeapon->SetActorEnableCollision(false);
}

void ABorisCharacter::OnMainAttackSwingStarted()
{
	bIsPerformingMainAttack = true;
	
	if(RightFistWeapon)
		RightFistWeapon->SetActorEnableCollision(true);
}
