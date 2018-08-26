// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "TankProjectileMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile() :
    ProjectileMovementComp( nullptr )
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    ProjectileMovementComp = CreateDefaultSubobject<UTankProjectileMovementComponent>( FName( "Projectile" ) );

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile( float speed )
{
    ProjectileMovementComp->SetVelocityInLocalSpace( FVector::ForwardVector * speed );
    ProjectileMovementComp->Activate();
    UE_LOG( LogTemp, Warning, TEXT( "Tank fires!" ) );
}

