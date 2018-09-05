// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UTankProjectileMovementComponent;
class UStaticMeshComponent;
class UParticleSystemComponent;
class URadialForceComponent;

UCLASS()
class U4PROJECT_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    void LaunchProjectile( float speed );

	void OnKillTimerTimeout();


private:
	UFUNCTION()
	void OnHit( UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit );

    UTankProjectileMovementComponent* ProjectileMovementComp;

	UPROPERTY( VisibleAnywhere, Category = "Components" )
	UStaticMeshComponent* CollisionMesh;

	UPROPERTY( VisibleAnywhere, Category = "Components" )
	UParticleSystemComponent* LaunchBlast;

	UPROPERTY( VisibleAnywhere, Category = "Components" )
	UParticleSystemComponent* ImpactBlast;

	UPROPERTY( VisibleAnywhere, Category = "Components" )
	URadialForceComponent* ExplosionForce;

	UPROPERTY( EditDefaultsOnly , Category = "Damage" )
	float Damage;
	
	float DestroyDelay{ 10 };
};
