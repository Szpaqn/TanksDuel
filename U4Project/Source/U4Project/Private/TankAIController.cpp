// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>( GetPawn() );
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto tank=GetControlledTank();
	if( tank!=nullptr )
	{
		UE_LOG( LogTemp, Warning, TEXT( "ATankAIController BeginPlay possesed tank:  %s" ), *tank->GetName() );
	}
	else
	{
		UE_LOG( LogTemp, Warning, TEXT( "ATankAIController BeginPlay !! NOT POSSESING A TANK !! " ) );
	}


}

