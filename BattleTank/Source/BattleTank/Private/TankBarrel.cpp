// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time (to be framerate independent).
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate Called at speed %f"), DegreesPerSecond);
}