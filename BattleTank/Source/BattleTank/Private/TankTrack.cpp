// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);

	auto ForceApplied = Throttle * TrackMaxDrivingForce * GetForwardVector();
	auto ForceLocation = GetComponentLocation();
	auto TankRootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRootComponent->AddForceAtLocation(ForceApplied, ForceLocation);
}


