// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent() :
    Barrel( nullptr )
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
    Super::BeginPlay();

    // ...

}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
    Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

    // ...
}

void UTankAimingComponent::AimAtTank( FVector aimTarget, float lounchSpeed )
{
    auto tankRequestingAim = GetOwner();
    if( tankRequestingAim && Barrel )
    {
        auto outletLocation = Barrel->GetSocketLocation( "Projectile" );
        UE_LOG( LogTemp, Warning, TEXT( "Tank %s aiming at pos: %s from pos: %s at speed: %f" ), *tankRequestingAim->GetName(), *aimTarget.ToString(), *barrelPos.ToString(), lounchSpeed );
    }
}

