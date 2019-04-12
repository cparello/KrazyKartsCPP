// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKart.generated.h"

UCLASS()
class KRAZYKARTSCPP_API AGoKart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGoKart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void UpdateLocationFromVelocity(float DeltaTime);
	void ApplyRotation(float DeltaTime);
	FVector GetAirResistance();

	FVector GetRollingResistance();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
private:
	//mass of the car in KG
	UPROPERTY(EditAnywhere)
	float Mass = 1000.0f;

	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000.0f;

	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecondRot = 90.0f;

	UPROPERTY(EditAnywhere)
	float DragCoefficient = 16.0f;

	UPROPERTY(EditAnywhere)
	float RollingResistanceCoefficient = 0.015f;

	FVector Velocity;
	float SteeringThrow;

	void MoveForward(float Value);
	void MoveRight(float Value);

	float Throttle;
};
