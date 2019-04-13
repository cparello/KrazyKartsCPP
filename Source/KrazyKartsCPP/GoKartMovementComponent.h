// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GoKartMovementComponent.generated.h"


USTRUCT()
struct FGoKartMove
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY()
		float Throttle;
	UPROPERTY()
		float SteeringThrow;

	UPROPERTY()
		float DeltaTime;
	UPROPERTY()
		float Time;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KRAZYKARTSCPP_API UGoKartMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGoKartMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SimulateMove(const FGoKartMove& Move);


	FVector GetVelocity() { return Velocity; };
	void SetVelocity(FVector Value) { Velocity = Value; };
	void SetSteeringThrow(float Value) { SteeringThrow = Value; };
	void SetThrottle(float Value) { Throttle = Value; };

	FGoKartMove GetLastMove() { return LastMove; };


private:

	FGoKartMove CreateMove(float DeltaTime);

	void UpdateLocationFromVelocity(float DeltaTime);
	void ApplyRotation(float DeltaTime, float SteeringThrow);
	FVector GetAirResistance();

	FVector GetRollingResistance();

	FVector Velocity;
	//mass of the car in KG
	UPROPERTY(EditAnywhere)
		float Mass = 1000.0f;

	UPROPERTY(EditAnywhere)
		float MaxDrivingForce = 10000.0f;

	UPROPERTY(EditAnywhere)
		float MinTurningRadius = 10.0f;

	UPROPERTY(EditAnywhere)
		float DragCoefficient = 16.0f;

	UPROPERTY(EditAnywhere)
		float RollingResistanceCoefficient = 0.015f;

	float SteeringThrow;

	float Throttle;


	FGoKartMove LastMove;
	
};
