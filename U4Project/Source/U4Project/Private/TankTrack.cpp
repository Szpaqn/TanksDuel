// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

#include "SprungWheel.h"
#include "SpawnPoint.h"

UTankTrack::UTankTrack() :
    MaxForce( 3000000 )
{
    PrimaryComponentTick.bCanEverTick = true;
}


void UTankTrack::SetThrottle(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(CurrentThrottle);
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{
	auto forceApplied = CurrentThrottle * MaxForce;
	auto wheels = GetWheels();
	auto forcePerWheel = forceApplied / wheels.Num();
	for (ASprungWheel* wheel : wheels)
	{
		wheel->AddDrivingForce(forcePerWheel);
	}
}

TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<ASprungWheel*> resultArray;
	TArray<USceneComponent*> children;
	GetChildrenComponents(true, children);
	for (USceneComponent* child : children)
	{
		auto spawnPointChild = Cast<USpawnPoint>(child);
		if (!spawnPointChild) continue;

		AActor* spawnedChild = spawnPointChild->GetSpawnedActor();
		auto sprungWheel = Cast<ASprungWheel>(spawnedChild);
		if (!sprungWheel) continue;

		resultArray.Add(sprungWheel);
	}
	return resultArray;
}
