// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// Move Towards The Player
		MoveToActor(PlayerTank, AcceptanceRadius);

		//Aiming at Player
		AITank->AimAt(PlayerTank->GetActorLocation());

		AITank->Fire();  //TODO Don't fire every frame
	}
}