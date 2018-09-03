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

private:
    float minRadiusToPlayer{ 6000 };

    virtual void Tick( float DeltaTime ) override;

};
