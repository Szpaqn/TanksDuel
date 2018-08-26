// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup = ( Custom ), meta = ( BlueprintSpawnableComponent ) )
class U4PROJECT_API UTankAimingComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UTankAimingComponent();

public:

    void AimAtTank( FVector aimTarget, float lounchSpeed);

    void MoveBarrel( FVector aimDirection );

    void SetBarrel( UTankBarrel* barrel ) { Barrel = barrel; }
    void SetTurret( UTankTurret* turret ) { Turret = turret; }

private:
    UTankBarrel* Barrel;
    UTankTurret* Turret;

};
