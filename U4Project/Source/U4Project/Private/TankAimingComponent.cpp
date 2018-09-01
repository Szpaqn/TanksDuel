// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Tank.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent() :
    FiringState( EFiringState::AMING )
    , Barrel( nullptr )
    , Turret( nullptr )
    , IsBarrelMoving( false )
    , PreviousDeltaRot()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
}


void UTankAimingComponent::TickComponent( float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction )
{
    Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

    auto tankUsing = Cast<ATank>(GetOwner());

    if( tankUsing && Barrel && Turret )
    {
        if( !tankUsing->IsReloaded() )
        {
            FiringState = EFiringState::RELOADING;
        }
        else if( IsBarrelMoving )
        {
            FiringState = EFiringState::AMING;
        }
        else
        {
            FiringState = EFiringState::LOCKED;
        }
    }
}

void UTankAimingComponent::AimAtTank( FVector aimTarget, float launchSpeed )
{
    auto tankRequestingAim = GetOwner();
    if( tankRequestingAim && Barrel && Turret )
    {
        FVector outLaunchVelocity;
        auto outletLocation = Barrel->GetSocketLocation( "Projectile" );

        //Calculate the outLaunchVelocity
        if( UGameplayStatics::SuggestProjectileVelocity( this, outLaunchVelocity, outletLocation, aimTarget, launchSpeed,
            false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace ) )
        {
            auto aimDirection = outLaunchVelocity.GetSafeNormal();
            //UE_LOG( LogTemp, Warning, TEXT( "Tank %s aiming at pos: %s" ), *tankRequestingAim->GetName(), *aimDirection.ToString() );
            MoveBarrel( aimDirection );
        }
        else
        {
            UE_LOG( LogTemp, Warning, TEXT( "Tank %s aiming solution not found" ), *tankRequestingAim->GetName() );
        }
    }
}

void UTankAimingComponent::MoveBarrel( FVector aimDirection )
{
    auto barrelRotator = Barrel->GetForwardVector().Rotation();
    auto aimAsRotator = aimDirection.Rotation();

    auto deltaRotator = aimAsRotator - barrelRotator;

    IsBarrelMoving = !PreviousDeltaRot.Equals( deltaRotator, 0.1 );

    Barrel->ElevateTheBarrel( deltaRotator.Pitch );

    Turret->RotateTheTurret( deltaRotator.Yaw );

    PreviousDeltaRot = deltaRotator;
}
