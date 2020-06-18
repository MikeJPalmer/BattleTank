// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();
	auto AIFoundPlayerTank = GetPlayerTank();

	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI is not possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI is possessing: %s"), *AIControlledTank->GetName());
	}

	if (!AIFoundPlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI did not find possessed player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI found player tank: %s"), *AIFoundPlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		// TODO Move Towards The Player

		//Aiming at Player
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// TODO Fire at player if ready
	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}