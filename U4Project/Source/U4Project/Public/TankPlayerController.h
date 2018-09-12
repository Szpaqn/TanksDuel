// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <utility>
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 *
 */
UCLASS()
class U4PROJECT_API ATankPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    UFUNCTION( BlueprintCallable, Category = "Setup" )
    ATank* GetControlledTank() const;

    virtual void BeginPlay() override;

    std::pair<bool, FVector> GetSightRayHitLocation();
    std::pair<bool, FVector> GetLookVectorHitLocation( FVector LookDirection ) const;
								  
	UFUNCTION( BlueprintCallable, Category = "death" ) 
	FString returnStateStr() { return deadStr; }

	UPROPERTY( EditAnywhere, Category = "death" )
	FString deadStr{};
private:
    virtual void Tick( float DeltaTime ) override;

    void AimTowardsCrosshair();

    UPROPERTY( EditAnywhere )
    float CrosshairXLocation{ 0.5 };

    UPROPERTY( EditAnywhere )
    float CrosshairYLocation{ 0.3 };

    UPROPERTY( EditAnywhere )
    int32 LineTraceRange{ 1000000 }; //10 * 1000 * 100 cm

	virtual void SetPawn( APawn* pawn ) override;

	UFUNCTION()
	void OnThisTankDeath();
};
