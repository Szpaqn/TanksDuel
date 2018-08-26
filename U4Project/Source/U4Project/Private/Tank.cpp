// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"



// Sets default values
ATank::ATank() :
    TankAimingComponent( nullptr )
    , LounchSpeed( 70000 )
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>( FName( "Aiming Component" ) );

}

void ATank::AimAt( FVector hitLocation )
{
    TankAimingComponent->AimAtTank( hitLocation, LounchSpeed );
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
    TankAimingComponent->SetBarrel( barrel );
}

void ATank::SetTurret( UTankTurret * turret )
{
    TankAimingComponent->SetTurret( turret );
}

