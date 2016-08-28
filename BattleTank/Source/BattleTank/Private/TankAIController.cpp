// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
//#include "TankAIController.h"
#include "../Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay in TankAIController"))

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

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());//GetPawn Already returns a pointer
}
