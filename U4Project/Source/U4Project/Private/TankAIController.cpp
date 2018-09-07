// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"

void ATankAIController::SetPawn( APawn * pawn )
{
	Super::SetPawn( pawn );

	if( pawn )
	{
		auto thisTank = dynamic_cast< ATank* >( pawn );

		if( !ensure( thisTank ) ) { return; }

		thisTank->OnDeath.AddUniqueDynamic( this, &ATankAIController::OnThisTankDeath );
	}
}

void ATankAIController::Tick( float DeltaTime )
{
    Super::Tick( DeltaTime );

    auto thisTank = Cast<ATank>( GetPawn() );
    if( thisTank == nullptr )
    {
        UE_LOG( LogTemp, Warning, TEXT( "ATankAIController BeginPlay !! NOT POSSESING A TANK !! " ) );
    }
    else
    {
        auto playerTank = Cast<ATank>( GetWorld()->GetFirstPlayerController()->GetPawn() );
        if( playerTank )
        {
            MoveToActor( playerTank, minRadiusToPlayer );

            thisTank->AimAt( playerTank->GetActorLocation() );

            auto aimingComponentState = thisTank->GetTankAimingComponent()->GetFiringState();

            if( aimingComponentState == EFiringState::LOCKED )
                thisTank->Fire();
        }
        else
        {
            UE_LOG( LogTemp, Warning, TEXT( "ATankAIController BeginPlay !! PLAYER TANK NOT FOUND !! " ) );
        }
    }

}

void ATankAIController::OnThisTankDeath()
{
	GetPawn()->DetachFromControllerPendingDestroy();
}

