// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

//Has barrel parameters and elevates it
UCLASS(meta = (BlueprintSpawnableComponent))//, hidecategories = "Collision")
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DeltaAngle);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 5;//just a default sensible value, can be changed in inspector

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevation = 30;//just a default sensible value, can be changed in inspector

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevation = 0;//just a default sensible value, can be changed in inspector
	
};
