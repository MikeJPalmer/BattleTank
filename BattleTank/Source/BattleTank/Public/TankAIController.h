// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS() class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	

private:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	
	//How close can the AI tank get to the player
	float AcceptanceRadius = 3000.f;
};
