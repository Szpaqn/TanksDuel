// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "TankProjectileMovementComponent.generated.h"

/**
 * 
 */
class AProjectile;
class UTankBarrel;

UCLASS( ClassGroup = ( Custom ), meta = ( BlueprintSpawnableComponent ) )
class U4PROJECT_API UTankProjectileMovementComponent : public UProjectileMovementComponent
{
	GENERATED_BODY()
	
public:
    UTankProjectileMovementComponent();
    UTankProjectileMovementComponent( AProjectile* projectile, UTankBarrel* barrel );

    void AimAtTank( FVector aimTarget, float LaunchSpeed);

    void MoveBarrel( FVector aimDirection );

    void SetProjectile( AProjectile* projectile ) { Projectile = projectile; }
    void SetBarrel( UTankBarrel* barrel ) { Barrel = barrel; }

private:
    AProjectile* Projectile;
    UTankBarrel* Barrel;

	
	
};
