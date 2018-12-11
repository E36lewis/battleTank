// Fill out your copyright notice in the Description page of Project Settings.


#include "TankController.h"
#include "BattleTank.h"
#include "Engine/World.h"

//Tink
	//Super
	//AimTowardsCrosshair()

void ATankController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player Tank started, not controlled by ai"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player Tank started possing: %s"), *(ControlledTank->GetName()));
	}
}

void ATankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("The cross hair is tickin"));

}



ATank* ATankController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

void ATankController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{ 
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		(GetLookVectorHitLocation(LookDirection, HitLocation));
	}

	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
	//FHitResult hit;
	return true;
}

bool ATankController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}

bool ATankController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false; //Line trace did not succeed
}
