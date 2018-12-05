// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestThirdPersonCharacter.h"
#include "BorisCharacter.generated.h"

UCLASS()
class TESTTHIRDPERSON_API ABorisCharacter : public ATestThirdPersonCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABorisCharacter();

	/** Primary Attack A Montage */
	UPROPERTY(EditDefaultsOnly, Category = Attack)
	class UAnimMontage *PrimaryAttack_A_Montage;

	UPROPERTY(EditDefaultsOnly, Category = FistWeapon)
	class UClass *RightFistWeaponClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TestScore; // Temp
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void StartAttacking() override;

	// Called locally on client, executed on the server.
	UFUNCTION(Server, reliable, WithValidation)
	void NotifyServerOfMainAttack();

	// When the server notifies that bIsPerformingMainAttack changed.
	UFUNCTION()
	void MainAttackChanged();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Main attack swing functions
	UFUNCTION(BlueprintCallable, Category=Attack)
	bool IsPerformingMainAttack() { return bIsPerformingMainAttack; }
	UFUNCTION(BlueprintCallable, Category = Attack)
	void OnMainAttackSwingFinished();
	UFUNCTION(BlueprintCallable, Category = Attack)
	void OnMainAttackSwingStarted();

private:
	class AFistWeapon *RightFistWeapon;

	UPROPERTY(ReplicatedUsing = MainAttackChanged)
	bool bIsPerformingMainAttack;
};
