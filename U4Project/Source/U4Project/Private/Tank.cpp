// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankTrack.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"


// Sets default values
ATank::ATank() :
    TankAimingComponent( nullptr )
    , LaunchSpeed( 20000 )
    , Barrel( nullptr )    
    , ReloadTime( 2 )
    , CurrentReloadTime( 0 )
	, StartingHealth( 100 )
	, CurrentHealth( StartingHealth )
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>( FName( "Aiming Component" ) );
    TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>( FName( "Movement Component" ) );

}


void ATank::AimAt( FVector hitLocation )
{
    TankAimingComponent->AimAtTank( hitLocation, LaunchSpeed );
}

bool ATank::IsReloaded()
{
    return ( FPlatformTime::Seconds() - CurrentReloadTime ) > ReloadTime;
}

void ATank::Fire()
{

    if( IsReloaded() )
    {
        if( Barrel )
        {
            auto projectile = GetWorld()->SpawnActor<AProjectile>( ProjectileBlueP, 
                Barrel->GetSocketLocation( FName( "Projectile" ) ), 
                Barrel->GetSocketRotation( FName( "Projectile" ) ) );

            projectile->LaunchProjectile( LaunchSpeed );
            CurrentReloadTime = FPlatformTime::Seconds();
            //UE_LOG( LogTemp, Warning, TEXT( "TANK %s Fire !! " ), *this->GetName() );
        }
    }
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
    Super::BeginPlay();

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent( UInputComponent* PlayerInputComponent )
{
    Super::SetupPlayerInputComponent( PlayerInputComponent );

}

void ATank::SetBarrel( UTankBarrel * barrel )
{
    Barrel = barrel;
    TankAimingComponent->SetBarrel( barrel );
}

void ATank::SetTurret( UTankTurret * turret )
{
    TankAimingComponent->SetTurret( turret );
}

void ATank::SetTrackLeft( UTankTrack * trackLeft )
{
    TrackLeft = trackLeft;
    TankMovementComponent->SetLeftTrack( trackLeft );
}

void ATank::SetTrackRight( UTankTrack * trackRight )
{
    TrackRight = trackRight;
    TankMovementComponent->SetRightTrack( trackRight );
}

float ATank::TakeDamage( float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser )
{
	int32 damagePoints = FPlatformMath::RoundToInt( DamageAmount );

	int32 damageToApply = FMath::Clamp( damagePoints, 0, CurrentHealth );

	UE_LOG( LogTemp, Warning, TEXT( "DamageAmount %f damagePoints %i damageToApply %i CurrentHealth %i" ), DamageAmount, damagePoints, damageToApply, CurrentHealth );

	CurrentHealth -= damageToApply;

	return static_cast<float>( damageToApply );
}

