// Fill out your copyright notice in the Description page of Project Settings.

#include "TankProjectileMovementComponent.h"

UTankProjectileMovementComponent::UTankProjectileMovementComponent() :
    Projectile( nullptr )
    , Barrel( nullptr )
{
    bAutoActivate = false;
}

UTankProjectileMovementComponent::UTankProjectileMovementComponent( AProjectile * projectile, UTankBarrel * barrel ) : 
    Projectile( projectile )
    , Barrel( barrel )
{
    bAutoActivate = false;
}
