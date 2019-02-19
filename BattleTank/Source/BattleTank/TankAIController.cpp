// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine.h"
#include "Tank.h"
#include "BattleTank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto Player = GetPlayerTank();
	if (!Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank started, not controlled by AI"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank started possing: %s"), *(Player->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{	
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}




ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTank() const
{
	auto Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(Player);
}