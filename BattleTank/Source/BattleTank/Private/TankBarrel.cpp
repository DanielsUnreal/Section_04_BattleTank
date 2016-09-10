// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float DeltaAngle)
{
	float RelativeSpeed = FMath::Clamp<float>(DeltaAngle,-1,1);//if the target aim is one or more degrees off, move at full speed

	auto ElevationInCurrentFrame = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = ElevationInCurrentFrame + RelativeRotation.Pitch;//Rotates Y axis, which goes from side to side of the tank
	auto NewElevation = FMath::Clamp<float>(RawNewElevation,MinElevation,MaxElevation);

	SetRelativeRotation(FRotator(NewElevation,0,0));
}

