// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <utility>
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 *
 */
UCLASS()
class U4PROJECT_API ATankPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ATank* GetControlledTank() const;

    virtual void BeginPlay() override;

    std::pair<bool, FVector> GetSightRayHitLocation();
    std::pair<bool, FVector> GetLookVectorHitLocation( FVector LookDirection ) const;

private:
    virtual void Tick( float DeltaTime ) override;

    void AimTowardsCrosshair();

    UPROPERTY( EditAnywhere )
        float CrosshairXLocation{ 0.5 };

    UPROPERTY( EditAnywhere )
        float CrosshairYLocation{ 0.333333 };

    UPROPERTY( EditAnywhere )
        int32 LineTraceRange
    {
        1000000
    }; //10 * 1000 * 100 cm

};
