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
		//Rotate and elevate towards that position
		UE_LOG(LogTemp, Warning, TEXT("Hitting on: %s"), *HitLocation.ToString())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Out of range"))//Maybe change color of crosshair to red
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto CrosshairScreenLocation = FVector2D(CrossHairXLocation * ViewportSizeX, CrossHairYLocation * ViewportSizeY);
	

	FVector CameraToCrosshairWorldDirection;
	FVector CameraWorldLocation;
	if (GetLookDirection(CrosshairScreenLocation, CameraToCrosshairWorldDirection, CameraWorldLocation))
	{
		if (GetLookVectorHitLocation(HitLocation, CameraWorldLocation, CameraToCrosshairWorldDirection))
		{
			return true;
		}	
	}
	
	return false;
}


//"De-project" the screen position of the cross-hair to a world direction
bool ATankPlayerController::GetLookDirection(FVector2D CrosshairScreenLocation, FVector & LookDirection, FVector & CameraWorldLocation) const
{
	return DeprojectScreenPositionToWorld(CrosshairScreenLocation.X, CrosshairScreenLocation.Y, CameraWorldLocation, LookDirection);
}


//Line-trace along the look direction, and see what we hit (up to max range)
bool ATankPlayerController::GetLookVectorHitLocation(FVector & HitLocation, FVector CameraWorldLocation, FVector LookDirection) const
{
	FHitResult Hit;
	FVector LineTraceEnd = CameraWorldLocation + LookDirection*LineTraceRange;
	bool bLineTraceSucceeded = GetWorld()->LineTraceSingleByChannel(
		Hit,
		CameraWorldLocation,
		LineTraceEnd,
		ECC_Visibility
	);
	HitLocation = Hit.ImpactPoint;
	return bLineTraceSucceeded;
}

