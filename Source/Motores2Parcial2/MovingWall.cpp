// MovingWall.cpp

#include "MovingWall.h"

AMovingWall::AMovingWall()
{
    PrimaryActorTick.bCanEverTick = true;
    MovementDistance = 150.0f;
    MovementSpeed = 100.0f;
    bMovingUp = true;
}

void AMovingWall::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = GetActorLocation();
    TargetLocation = StartLocation + FVector(0.0f, 0.0f, MovementDistance);
}

void AMovingWall::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector CurrentLocation = GetActorLocation();
    FVector NewLocation = CurrentLocation;

    float MovementDelta = MovementSpeed * DeltaTime;

    if (bMovingUp)
    {
        NewLocation.Z += MovementDelta;
        if (NewLocation.Z >= StartLocation.Z + MovementDistance)
        {
            NewLocation.Z = StartLocation.Z + MovementDistance;
            bMovingUp = false;
        }
    }
    else
    {
        NewLocation.Z -= MovementDelta;
        if (NewLocation.Z <= StartLocation.Z)
        {
            NewLocation.Z = StartLocation.Z;
            bMovingUp = true;
        }
    }

    SetActorLocation(NewLocation);
}
//verga de dinosaurio gemelo