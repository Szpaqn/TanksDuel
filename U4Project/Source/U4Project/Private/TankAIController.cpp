// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "TankAimingComponent.h"

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

