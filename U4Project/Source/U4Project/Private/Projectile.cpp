// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "TankProjectileMovementComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/EngineTypes.h"

// Sets default values
AProjectile::AProjectile() :
    ProjectileMovementComp( nullptr )
	, CollisionMesh( nullptr )
	, LaunchBlast( nullptr )
	, ImpactBlast( nullptr )
	, ExplosionForce( nullptr )
	, Damage( 20 )
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>( FName( "Collision Mesh" ) );
	SetRootComponent( CollisionMesh );
	CollisionMesh->SetNotifyRigidBodyCollision( true );  //as default

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>( FName( "Launch Blast" ) );
	LaunchBlast->AttachToComponent( RootComponent, FAttachmentTransformRules::KeepRelativeTransform );

	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>( FName( "Impact Blast" ) );
	ImpactBlast->AttachToComponent( RootComponent, FAttachmentTransformRules::KeepRelativeTransform );
	ImpactBlast->bAutoActivate = false;

    ProjectileMovementComp = CreateDefaultSubobject<UTankProjectileMovementComponent>( FName( "Projectile" ) );
	ProjectileMovementComp->bAutoActivate = false;

	ExplosionForce = CreateDefaultSubobject<URadialForceComponent>( FName( "Explosion Force" ) );
	ExplosionForce->AttachToComponent( RootComponent, FAttachmentTransformRules::KeepRelativeTransform );

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionMesh->OnComponentHit.AddDynamic( this, &AProjectile::OnHit );
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

void AProjectile::OnKillTimerTimeout()
{
	Destroy();
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	LaunchBlast->Deactivate();
	ImpactBlast->Activate();
	ExplosionForce->FireImpulse();
	CollisionMesh->DestroyComponent();

	UGameplayStatics::ApplyRadialDamage( this, Damage, ExplosionForce->GetComponentLocation(), ExplosionForce->Radius, UDamageType::StaticClass(), TArray<AActor*>() );

	FTimerHandle timer;
	//GetWorld()->GetTimerManager().SetTimer( timer, this, [this]() { this->Destroy(); }, DestroyDelay, false ); //lambdas don't work :/
	GetWorld()->GetTimerManager().SetTimer( timer, this, &AProjectile::OnKillTimerTimeout, DestroyDelay, false );
}

