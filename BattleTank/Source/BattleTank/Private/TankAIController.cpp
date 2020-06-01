// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

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

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}