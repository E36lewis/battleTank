// Fill out your copyright notice in the Description page of Project Settings.


#include "TankController.h"
#include "BattleTank.h"

//Tink
	//Super
	//AimTowardsCrosshair()

void ATankController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank started, not controlled by ai"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank started possing: %s"), *(ControlledTank->GetName()));
	}
}

void ATankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//AimTowardsCrosshair();
	UE_LOG(LogTemp, Warning, TEXT("The cross hair is tickin"));

}



ATank* ATankController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}



