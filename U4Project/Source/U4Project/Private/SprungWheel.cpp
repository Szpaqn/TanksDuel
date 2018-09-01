// Fill out your copyright notice in the Description page of Project Settings.

#include "SprungWheel.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
ASprungWheel::ASprungWheel() : 
    Mass( nullptr )
    , Wheel( nullptr )
    , MassWheelConstraint( nullptr )
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Mass = CreateDefaultSubobject<UStaticMeshComponent>( FName( "Mass" ) );
    SetRootComponent( Mass );

    Wheel = CreateDefaultSubobject<UStaticMeshComponent>( FName( "Wheel" ) );
    Wheel->SetupAttachment( Mass );

    MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>( FName( "Constraint" ) );
}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

