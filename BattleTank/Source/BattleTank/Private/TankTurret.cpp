// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float DeltaAngle)
{
	float RelativeSpeed = FMath::Clamp<float>(DeltaAngle, -1, 1);//if the target aim is one or more degrees off, move at full speed
	
	auto RotationInCurrentFrame = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationInCurrentFrame;
	
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}

