// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Environment/THBaseEnvironmentHUBActor.h"
#include "THTrophyHub.generated.h"

/**
 *
 */
UCLASS()
class TREASUREHUNTING_API ATHTrophyHub : public ATHBaseEnvironmentHUBActor
{
    GENERATED_BODY()
public:
    void SpawnChest(FTransform Transform);
    void SetFloorSize(FVector FloorInstanceSize) { FloorSize = FloorInstanceSize; }


private:
    int32 MakeRandomOddNumber(int32 Min, int32 Max) const;
    FVector FloorSize;

    UPROPERTY()
    ATHBaseActor* ChestActor = nullptr;
};
