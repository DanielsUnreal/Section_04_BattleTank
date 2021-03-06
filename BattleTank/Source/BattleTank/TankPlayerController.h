// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be the last include

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Set Crosshair Color Event"))
	void SetCrosshairColor(FLinearColor Color);

private:
	
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds ) override;

	ATank* GetControlledTank() const;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector & HitLocation) const;

	bool GetLookDirection(FVector2D CrosshairScreenLocation, FVector& LookDirection, FVector & CameraWorldLocation) const;

	bool GetLookVectorHitLocation(FVector& HitLocation, FVector CameraWorldLocation, FVector LookDirection) const;


	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 20000;//in cm
};
