// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"

//// Called every frame
//void UTankBarrel::Tick( float DeltaTime )
//{
//    Super::Tick( DeltaTime );
//
//}

void UTankBarrel::ElevateTheBarrel( float relativeSpeed )
{
    auto elevationChange = relativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

    auto rawNewElevation = RelativeRotation.Pitch + elevationChange;

    rawNewElevation = FMath::Clamp<float>( rawNewElevation, MinElevation, MaxElevation );

    SetRelativeRotation( FRotator( rawNewElevation, 0, 0 ) );
}

