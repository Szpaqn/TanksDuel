// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <utility>
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


class ATank;

/**
 *
 */
UCLASS()
class U4PROJECT_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	UFUNCTION( BlueprintCallable, Category = "death" ) 
	FString returnStateStr() { return deadStr; }

	UPROPERTY( EditAnywhere, Category = "death" )
	FString deadStr{};
private:
    float minRadiusToPlayer{ 4000 };

	virtual void SetPawn( APawn* pawn ) override;

    virtual void Tick( float DeltaTime ) override;

	UFUNCTION()
	void OnThisTankDeath();
};
