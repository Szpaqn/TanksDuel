// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack() :
    MaxForce( 100000 )
{

}

void UTankTrack::SetThrottle( float throttle )
{
    auto forceApplied = GetForwardVector() * throttle * MaxForce;
    auto forceLocation = GetComponentLocation();
    auto tankBody = Cast<UPrimitiveComponent>( GetOwner()->GetRootComponent() );

    tankBody->AddForceAtLocation( forceApplied, forceLocation );
}


