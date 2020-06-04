// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("You are possessing: %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{	
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation))
	{

		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *OutHitLocation.ToString());
		// TODO Tell controlled tank to aim at this point.
	}

	
}

// Get World location if linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 OutViewportSizeX, OutViewportSizeY;
	GetViewportSize(OutViewportSizeX, OutViewportSizeY); //Gets the size of the entire viewport which is the screen when playing.
	FVector2D ScreenLocation = FVector2D(OutViewportSizeX * CrossHairXLocation, OutViewportSizeY * CrossHairYLocation);

	// "De-project" the screen position of the cursor/crosshair to a world position

	// Line-trace along that look direction, and see what we hit (up to some max range)
	return true;
}