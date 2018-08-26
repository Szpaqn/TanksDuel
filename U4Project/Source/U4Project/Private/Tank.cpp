// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"


// Sets default values
ATank::ATank() :
    TankAimingComponent( nullptr )
    , LaunchSpeed( 10000 )
    , Barrel( nullptr )
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>( FName( "Aiming Component" ) );

}

void ATank::AimAt( FVector hitLocation )
{
    TankAimingComponent->AimAtTank( hitLocation, LaunchSpeed );
}

void ATank::Fire()
{
    if( Barrel )
    {
        auto projectile = GetWorld()->SpawnActor<AProjectile>( ProjectileBlueP, 
            Barrel->GetSocketLocation( FName( "Projectile" ) ), 
            Barrel->GetSocketRotation( FName( "Projectile" ) ) );

        projectile->LaunchProjectile( LaunchSpeed );
    }
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
    Super::BeginPlay();

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent( UInputComponent* PlayerInputComponent )
{
    Super::SetupPlayerInputComponent( PlayerInputComponent );

}

void ATank::SetBarrel( UTankBarrel * barrel )
{
    Barrel = barrel;
    TankAimingComponent->SetBarrel( barrel );
}

void ATank::SetTurret( UTankTurret * turret )
{
    TankAimingComponent->SetTurret( turret );
}

