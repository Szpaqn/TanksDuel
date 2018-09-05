// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "TankProjectileMovementComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AProjectile::AProjectile() :
    ProjectileMovementComp( nullptr )
	, CollisionMesh( nullptr )
	, LaunchBlast( nullptr )
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>( FName( "Collision Mesh" ) );
	SetRootComponent( CollisionMesh );
	CollisionMesh->SetNotifyRigidBodyCollision( true );  //as default
	CollisionMesh->SetVisibility( false );

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>( FName( "Launch Blast" ) );
	LaunchBlast->AttachTo( RootComponent );

    ProjectileMovementComp = CreateDefaultSubobject<UTankProjectileMovementComponent>( FName( "Projectile" ) );
	ProjectileMovementComp->bAutoActivate = false;
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

