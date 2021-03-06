// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Forward Decleration
class UTankBarrel;
class UTankTurrent;

//Holds barrels properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurrentReference(UTankTurrent* TurrentToSet);
	void AimAt(FVector HitLocation, float LaunchSpeed);


protected:

private:	
	// Called every frame

	 UTankBarrel* Barrel = nullptr;
	 UTankTurrent* Turrent = nullptr;

	 void MoveBarrelTowards(FVector AimDirection);
};
