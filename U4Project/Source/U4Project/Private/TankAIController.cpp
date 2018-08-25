// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>( GetPawn() );
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>( GetWorld()->GetFirstPlayerController()->GetPawn() );
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto tank = GetControlledTank();
	if( tank != nullptr )
	{
		UE_LOG( LogTemp, Warning, TEXT( "ATankAIController BeginPlay possesed tank:  %s" ), *tank->GetName() );
	}
	else
	{
		UE_LOG( LogTemp, Warning, TEXT( "ATankAIController BeginPlay !! NOT POSSESING A TANK !! " ) );
	}

	auto playerTank = GetPlayerTank();
	if( playerTank != nullptr )
	{
		UE_LOG( LogTemp, Warning, TEXT( "ATankAIController BeginPlay found player tank:  %s" ), *playerTank->GetName() );
	}
	else
	{
		UE_LOG( LogTemp, Warning, TEXT( "ATankAIController BeginPlay !! PLAYER TANK NOT FOUND !! " ) );
	}


}

void ATankAIController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if( GetPlayerTank() )
	{
		GetControlledTank()->AimAt( GetPlayerTank()->GetActorLocation() );
	}

}
