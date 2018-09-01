// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::MoveForwardBack( float throttle )
{
    FMath::Clamp<float>( throttle, -1, 1 );

    //UE_LOG( LogTemp, Warning, TEXT( "Tank moving T: %f" ), throttle );
    LeftTrack->SetThrottle( throttle );
    RightTrack->SetThrottle( throttle );
}

void UTankMovementComponent::Turn( float throttle )
{
    //UE_LOG( LogTemp, Warning, TEXT( "Tank turning T: %f" ), throttle );
    throttle < 0 ? TurnLeft( throttle ) : TurnRight( throttle );
}

void UTankMovementComponent::TurnLeft( float throttle )
{
    FMath::Clamp<float>( throttle, -1, 0 );

    //UE_LOG( LogTemp, Warning, TEXT( "Tank moving left" ) );
    LeftTrack->SetThrottle( throttle );
}

void UTankMovementComponent::TurnRight( float throttle )
{
    FMath::Clamp<float>( throttle, 0, 1 );

    //UE_LOG( LogTemp, Warning, TEXT( "Tank moving right" ) );
    LeftTrack->SetThrottle( throttle );
}

void UTankMovementComponent::RequestDirectMove( const FVector & MoveVelocity, bool bForceMaxSpeed )
{
    auto tankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto whereShoulTankGo = MoveVelocity.GetSafeNormal();

    MoveForwardBack( FVector::DotProduct( tankForward, whereShoulTankGo ) ); //COS() of the angle of two vectors

    Turn( FVector::CrossProduct( tankForward, whereShoulTankGo ).Z );  //SIN() of angle of two vectors
}
