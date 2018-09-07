// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankMovementComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;
class UTankTrack;

DECLARE_DYNAMIC_MULTICAST_DELEGATE( FTankDelegate );

UCLASS()
class U4PROJECT_API ATank : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    ATank();

    void AimAt( FVector hitLocation );

    bool IsReloaded();

    UFUNCTION( BlueprintCallable, Category = "Firing" )
    void Fire();

    UTankAimingComponent* GetTankAimingComponent() { return TankAimingComponent; }
	
	UFUNCTION( BlueprintPure, Category = "HealthBar" )
	float GetHealthLevel(); // between 0 and 1

	FTankDelegate OnDeath;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;


    UPROPERTY( BlueprintReadOnly, Category = "Firing" )
    UTankAimingComponent* TankAimingComponent;

    UPROPERTY( BlueprintReadOnly, Category = "Input" )
    UTankMovementComponent* TankMovementComponent;
public:
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent( class UInputComponent* PlayerInputComponent ) override;

    UFUNCTION( BlueprintCallable, Category = "Setup" )
    void SetBarrel( UTankBarrel* barrel );

    UFUNCTION( BlueprintCallable, Category = "Setup" )
    void SetTurret( UTankTurret* turret );
    
    UFUNCTION( BlueprintCallable, Category = "Setup" )
    void SetTrackLeft( UTankTrack* trackLeft );
    
    UFUNCTION( BlueprintCallable, Category = "Setup" )
    void SetTrackRight( UTankTrack* trackRight );
	
	UFUNCTION( BlueprintCallable, Category = "Damage" )
    float TakeDamage(
		float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator,
		AActor * DamageCauser
	) override;

private:
    UPROPERTY( EditDefaultsOnly, Category = "Firing" )
    float LaunchSpeed;

    UPROPERTY( EditDefaultsOnly, Category = "Firing" )
    TSubclassOf<AProjectile> ProjectileBlueP;

    UTankBarrel* Barrel;
    UTankTrack* TrackLeft;
    UTankTrack* TrackRight;

    UPROPERTY( EditDefaultsOnly, Category = "Firing" )
    float ReloadTime;

    float CurrentReloadTime;

	UPROPERTY( EditAnywhere, Category = "Health" )
	int32 StartingHealth;

	UPROPERTY( VisibleAnywhere, Category = "Health" )
	int32 CurrentHealth;
};
