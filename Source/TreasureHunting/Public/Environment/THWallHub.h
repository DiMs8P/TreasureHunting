// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "THBaseEnvironmentHUBActor.h"
#include "THCoreTypes.h"
#include "THWallHub.generated.h"

class ATHBaseActor;

UCLASS()
class TREASUREHUNTING_API ATHWallHub : public ATHBaseEnvironmentHUBActor
{
    GENERATED_BODY()

public:
    ATHWallHub();
    void GenerateMaze();

    void SetFloorSize(FVector FloorInstanceSize) { FloorSize = FloorInstanceSize; }

protected:
    virtual void BeginPlay() override;

private:

    void GetCoordsMap(TArray<int32>& Map, const int32& Lenght, const int32& Width);
    void FillStartCoordsMap(TArray<int32>& Map, const int32& Lenght, const int32& Width);
    void GetNeighbours(const int32 Height, const int32 Width, const TArray<int32>& Map, const FPoint StartPoint, TArray<FPoint>& Neighbors);
    void MakeHole(const int32 Width, const int32 X, const int32 Y, TArray<int>& Maze);

    void BuildLabirinth(TArray<int32>& InnerMap);

    UPROPERTY()
    TArray<ATHBaseActor*> Actors;

    FVector FloorSize;
};
