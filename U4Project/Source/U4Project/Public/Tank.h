// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;

UCLASS()
class U4PROJECT_API ATank : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    ATank();

    void AimAt( FVector hitLocation );

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;


    UTankAimingComponent* TankAimingComponent;
public:
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent( class UInputComponent* PlayerInputComponent ) override;

    UFUNCTION( BlueprintCallable, Category = Setup )
    void SetBarrel( UTankBarrel* barrel );


private:
    UPROPERTY( EditAnywhere, Category = Firing )
    float LounchSpeed;


};
