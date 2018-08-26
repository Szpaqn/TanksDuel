// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

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
            thisTank->AimAt( playerTank->GetActorLocation() );

            thisTank->Fire();
        }
        else
        {
            UE_LOG( LogTemp, Warning, TEXT( "ATankAIController BeginPlay !! PLAYER TANK NOT FOUND !! " ) );
        }
    }

}

