// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"


class UTankTrack;
/**
 * 
 */
UCLASS()
class U4PROJECT_API UTankMovementComponent : public UNavMovementComponent
{
    GENERATED_BODY()

    UFUNCTION( BlueprintCallable, Category = "Input" )
    void MoveForwardBack( float throttle);

    UFUNCTION( BlueprintCallable, Category = "Input" )
    void Turn( float throttle);

    //pathfinding
    void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
public:

    UFUNCTION( BlueprintCallable, Category = "Input" )
    void SetLeftTrack( UTankTrack* leftTrack ) { LeftTrack = leftTrack; }

    UFUNCTION( BlueprintCallable, Category = "Input" )
    void SetRightTrack( UTankTrack* rightTrack ) { RightTrack = rightTrack; }
	
private:
    UTankTrack* LeftTrack;
    UTankTrack* RightTrack;
};
