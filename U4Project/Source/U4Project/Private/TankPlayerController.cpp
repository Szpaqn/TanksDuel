// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"


ATank * ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>( GetPawn() );
}

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    auto tank = GetControlledTank();
    if( tank != nullptr )
    {
        //UE_LOG( LogTemp, Warning, TEXT( "ATankPlayerController BeginPlay possesed tank: %s" ), *tank->GetName() );
    }
    else
    {
        UE_LOG( LogTemp, Warning, TEXT( "ATankPlayerController BeginPlay !! NOT POSSESING A TANK !! " ) );
    }


}

void ATankPlayerController::Tick( float DeltaTime )
{
    Super::Tick( DeltaTime );

    AimTowardsCrosshair();

}

void ATankPlayerController::AimTowardsCrosshair()
{
    auto controlledTank = GetControlledTank();
    if( !controlledTank ) return;

    //raytrace from camera to 
    auto hittingPair = GetSightRayHitLocation();

    if( hittingPair.first ) //hit smth
    {
        //UE_LOG( LogTemp, Warning, TEXT( "ATankPlayerController hit, Pos: %s" ), *hittingPair.second.ToString() );
        controlledTank->AimAt( hittingPair.second );
    }
    else //didnt hit eny-th
    {
        //UE_LOG( LogTemp, Warning, TEXT( "ATankPlayerController not hit, Pos: %s" ), *hittingPair.second.ToString() );
    }

}

void ATankPlayerController::SetPawn( APawn * pawn )
{
	Super::SetPawn( pawn );

	if( pawn )
	{
		auto thisTank = dynamic_cast< ATank* >( pawn );

		if( !ensure( thisTank ) ) { return; }

		thisTank->OnDeath.AddUniqueDynamic( this, &ATankPlayerController::OnThisTankDeath );
	}
}

void ATankPlayerController::OnThisTankDeath()
{
	StartSpectatingOnly();
}

//void ATankPlayerController::StartSpectating()
//{
//}

std::pair<bool, FVector> ATankPlayerController::GetSightRayHitLocation()
{
    //Find the pos of the crosshair and line trace through.
    //Check if you hit smth

    int32 viewportSizeX, viewportSizeY;
    GetViewportSize( viewportSizeX, viewportSizeY );
    auto crosshairLocation = FVector2D{ viewportSizeX * CrosshairXLocation, viewportSizeY * CrosshairYLocation };

    FVector worldLocation, worldDirection;
    if( DeprojectScreenPositionToWorld( crosshairLocation.X, crosshairLocation.Y, worldLocation, worldDirection ) )
    {
        return GetLookVectorHitLocation( worldDirection );
    }

    return std::make_pair<bool, FVector>( bool{}, FVector{} );
}

std::pair<bool, FVector> ATankPlayerController::GetLookVectorHitLocation( FVector LookDirection ) const
{
    FHitResult hitResult;
    auto startLocation = PlayerCameraManager->GetCameraLocation();
    auto endLocation = startLocation + ( LookDirection * LineTraceRange );

    return std::pair<bool, FVector>{ GetWorld()->LineTraceSingleByChannel( hitResult, startLocation, endLocation, ECollisionChannel::ECC_Visibility ), hitResult.Location };
}
