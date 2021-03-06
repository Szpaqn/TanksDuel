// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS( meta = ( BlueprintSpawnableComponent ), hideCategories = ( "Collision" ) )
class U4PROJECT_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
       
    void RotateTheTurret( float relativeSpeed );

private:

    UPROPERTY( EditAnywhere, Category = "Setup" )
        float MaxDegreesPerSecond{ 60 };

    UPROPERTY( EditAnywhere, Category = "Setup" )
        float MaxRotation{ 360 };

    UPROPERTY( EditAnywhere, Category = "Setup" )
        float DefaultRotation{ 0 };
	
	
	
};
