// MovingWall.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingWall.generated.h"

UCLASS()
class MOTORES2PARCIAL2_API AMovingWall : public AActor
{
    GENERATED_BODY()

public:
    AMovingWall();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(EditAnywhere, Category = "Movement")
    float MovementDistance;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float MovementSpeed;

    FVector StartLocation;
    FVector TargetLocation;
    bool bMovingUp;
};

//verga de dinosaurio gemelo