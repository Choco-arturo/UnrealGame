// MovingPlatform.cpp

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;
    MovementDistance = 150.0f;
    MovementSpeed = 100.0f;
    RotationSpeed = 100.0f;
    bMovingForward = true;
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = GetActorLocation();
    TargetLocation = StartLocation + FVector(MovementDistance, 0.0f, 0.0f);
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Rotate the actor around its own axis
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += RotationSpeed * DeltaTime;
    SetActorRotation(NewRotation);

    FVector CurrentLocation = GetActorLocation();
    FVector NewLocation = CurrentLocation;

    float MovementDelta = MovementSpeed * DeltaTime;

    if (bMovingForward)
    {
        NewLocation.X += MovementDelta;
        if (NewLocation.X >= StartLocation.X + MovementDistance)
        {
            NewLocation.X = StartLocation.X + MovementDistance;
            bMovingForward = false;
        }
    }
    else
    {
        NewLocation.X -= MovementDelta;
        if (NewLocation.X <= StartLocation.X)
        {
            NewLocation.X = StartLocation.X;
            bMovingForward = true;
        }
    }

    SetActorLocation(NewLocation);
}
