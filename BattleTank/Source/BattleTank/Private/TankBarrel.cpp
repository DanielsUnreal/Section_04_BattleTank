// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed,-1,1);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = ElevationChange + RelativeRotation.Pitch;//Rotates Y axis, which goes from side to side of the tank
	auto NewElevation = FMath::Clamp<float>(RawNewElevation,MinElevation,MaxElevation);

	SetRelativeRotation(FRotator(NewElevation,0,0));
}

