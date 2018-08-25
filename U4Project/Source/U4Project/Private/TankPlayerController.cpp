// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>( GetPawn() );
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto tank=GetControlledTank();
	if( tank!=nullptr )
	{
		UE_LOG( LogTemp, Warning, TEXT( "ATankPlayerController BeginPlay possesed tank: %s" ), *tank->GetName() );
	}
	else
	{
		UE_LOG( LogTemp, Warning, TEXT( "ATankPlayerController BeginPlay !! NOT POSSESING A TANK !! " ) );
	}

	 
}
