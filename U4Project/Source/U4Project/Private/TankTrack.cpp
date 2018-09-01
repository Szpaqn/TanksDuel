// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack() :
    MaxForce( 10000000 )
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent( float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction )
{
    Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
}

void UTankTrack::SetThrottle( float throttle )
{
    auto forceApplied = GetForwardVector() * throttle * MaxForce;
    auto forceLocation = GetComponentLocation();
    auto tankBody = Cast<UPrimitiveComponent>( GetOwner()->GetRootComponent() );

    tankBody->AddForceAtLocation( forceApplied, forceLocation );
}


