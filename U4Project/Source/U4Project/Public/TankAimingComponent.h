// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UENUM()
enum class EFiringState : uint8
{
    RELOADING, AMING, LOCKED
};

UCLASS( ClassGroup = ( Custom ), meta = ( BlueprintSpawnableComponent ) )
class U4PROJECT_API UTankAimingComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UTankAimingComponent();

    void AimAtTank( FVector aimTarget, float LaunchSpeed);

    void MoveBarrel( FVector aimDirection );

    void SetBarrel( UTankBarrel* barrel ) { Barrel = barrel; }
    void SetTurret( UTankTurret* turret ) { Turret = turret; }

    void SetFiringState( EFiringState firingState ) { FiringState = firingState; }
    EFiringState GetFiringState() { return FiringState; }

protected:

    void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction );

    UPROPERTY( BlueprintReadOnly, Category = "State" )
    EFiringState FiringState;

private:
    UTankBarrel* Barrel;
    UTankTurret* Turret;

    bool IsBarrelMoving;
    FRotator PreviousDeltaRot;

};
