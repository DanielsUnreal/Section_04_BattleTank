// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

//Has barrel parameters and elevates it
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = "Collision")
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//min=-1, max=+1
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 5;//just a default sensible value, can be changed in inspector

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 30;//just a default sensible value, can be changed in inspector

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0;//just a default sensible value, can be changed in inspector
	
};
