// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay in TankPlayerController"))

	ATank* PossessedTank = GetControlledTank();
	if (PossessedTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Possessed: %s"), *PossessedTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No tank possessed"))
	}
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	
	return Cast<ATank>(GetPawn());//GetPawn Already returns a pointer
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	//TODO linetrace and aiming
}

