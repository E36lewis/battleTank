// Fill out your copyright notice in the Description page of Project Settings.


#include "TankController.h"
#include "BattleTank.h"

void ATankController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank started, not controlled by player"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank started possing: %s"), *(ControlledTank->GetName()));
	}
}



ATank* ATankController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}



