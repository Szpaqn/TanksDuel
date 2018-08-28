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

UCLASS()
class U4PROJECT_API ATank : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    ATank();

    void AimAt( FVector hitLocation );

    UFUNCTION( BlueprintCallable, Category = Firing )
    void Fire();


protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;


    UTankAimingComponent* TankAimingComponent;

    UPROPERTY( BlueprintReadOnly, Category = Input )
    UTankMovementComponent* TankMovementComponent;
public:
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent( class UInputComponent* PlayerInputComponent ) override;

    UFUNCTION( BlueprintCallable, Category = Setup )
    void SetBarrel( UTankBarrel* barrel );

    UFUNCTION( BlueprintCallable, Category = Setup )
    void SetTurret( UTankTurret* turret );
    
    UFUNCTION( BlueprintCallable, Category = Setup )
    void SetTrackLeft( UTankTrack* trackLeft );
    
    UFUNCTION( BlueprintCallable, Category = Setup )
    void SetTrackRight( UTankTrack* trackRight );

private:
    UPROPERTY( EditDefaultsOnly, Category = Firing )
    float LaunchSpeed;

    UPROPERTY( EditDefaultsOnly, Category = Firing )
    TSubclassOf<AProjectile> ProjectileBlueP;

    UTankBarrel* Barrel;
    UTankTrack* TrackLeft;
    UTankTrack* TrackRight;

    UPROPERTY( EditDefaultsOnly, Category = Firing )
    float ReloadTime;

    float CurrentReloadTime;
};
