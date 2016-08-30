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
	
	FVector HitLocation;//out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Aiming towards: %s"), *HitLocation.ToString())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot aim there"))
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//Find crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto CrosshairScreenLocation = FVector2D(CrossHairXLocation * ViewportSizeX, CrossHairYLocation * ViewportSizeY);
	

	FVector CameraToCrosshairWorldDirection;
	if (GetLookDirection(CrosshairScreenLocation, CameraToCrosshairWorldDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Aiming towards: %s"), *CameraToCrosshairWorldDirection.ToString())
	}
	

	//Line-trace along that look direction, and see what we hit (up to max range)


	return true;
}

//"De-project" the screen position of the cross-hair to a world direction
bool ATankPlayerController::GetLookDirection(FVector2D CrosshairScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(CrosshairScreenLocation.X, CrosshairScreenLocation.Y, CameraWorldLocation, LookDirection);
}

