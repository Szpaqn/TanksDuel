// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"

void UTankTurret::RotateTheTurret( float relativeSpeed )
{
    auto rotationSpeed = FMath::Clamp<float>( relativeSpeed, -1, 1 );
    auto rotationChange = rotationSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

    auto newRotation = RelativeRotation.Yaw + rotationChange;

    SetRelativeRotation( FRotator( 0, newRotation, 0 ) );
}
