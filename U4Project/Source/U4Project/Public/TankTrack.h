// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS( meta = ( BlueprintSpawnableComponent ) )
class U4PROJECT_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    UTankTrack();
       
    UFUNCTION( BlueprintCallable, Category = "Input" )
    void SetThrottle( float throttle );

    UPROPERTY( EditDefaultsOnly, Category = "TankTrack" )
    float MaxForce;
	

private:
	TArray<class ASprungWheel*> GetWheels() const;

	void DriveTrack( float CurrentThrottle );
};
