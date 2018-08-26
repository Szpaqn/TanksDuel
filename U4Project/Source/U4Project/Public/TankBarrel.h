// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 *
 */
UCLASS( meta = ( BlueprintSpawnableComponent ), hideCategories = ( "Collision" ) )
class U4PROJECT_API UTankBarrel : public UStaticMeshComponent
{
    GENERATED_BODY()

public:
    void ElevateTheBarrel( float relativeSpeed );

private:
    // Called every frame
    //virtual void Tick( float DeltaTime ) override;

    UPROPERTY( EditAnywhere, Category = Setup )
    float MaxDegreesPerSecond{ 10 };

    UPROPERTY( EditAnywhere, Category = Setup )
    float MaxElevation{ 40 };

    UPROPERTY( EditAnywhere, Category = Setup )
    float MinElevation{ -1 };

};
