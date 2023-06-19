// MovingPlatform.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class MOTORES2PARCIAL2_API AMovingPlatform : public AActor
{
    GENERATED_BODY()

public:
    AMovingPlatform();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(EditAnywhere, Category = "Movement")
    float MovementDistance;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float MovementSpeed;

    UPROPERTY(EditAnywhere, Category = "Rotation")
    float RotationSpeed;

    FVector StartLocation;
    FVector TargetLocation;
    bool bMovingForward;
};

