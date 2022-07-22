// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Environment/THBaseActor.h"
#include "EnvironmentHUBActor.generated.h"

UCLASS()
class TREASUREHUNTING_API AEnvironmentHUBActor : public AActor
{
    GENERATED_BODY()

public:
    AEnvironmentHUBActor();

    void GenerateMaze();

protected:
    virtual void BeginPlay() override;

    // MAKE A STRUCTURE OF IT!!!!!!!!
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes")
    TSubclassOf<ATHBaseActor> FloorInstance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes")
    TSubclassOf<ATHBaseActor> WallInstance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (ClampMin = "2", ClampMax = "100"))
    int32 MazeLength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (ClampMin = "2", ClampMax = "100"))
    int32 MazeWidth;

    TArray<ATHBaseActor*> Actors;

private:
    FVector FloorActorSize;
    FVector WallActorSize;

    ATHBaseActor* SpawnInstance(const FTransform& Transform, const TSubclassOf<ATHBaseActor>& Actor) const;
    void SpawnFloors() const;

    void ChangeActorPosition(const FVector& NewPosition);

    FVector GetActorSize(TSubclassOf<ATHBaseActor>& Actor) const;



    int MakeRandomOddNumber(int32 Min, int32 Max);

    void GetCoordsMap(TArray<int32>& Map, const int32& Lenght, const int32& Width, const FVector2D& StartCoord);

    void FillStartCoordsMap(TArray<int32>& Map, const int32& Lenght, const int32& Width);

    void GetNeighbours(
        const int32 Height, const int32 Width, const TArray<int32>& Map, const FVector2D StartPoint, TArray<FVector2D>& Neighbors);
    void MakeHole(const int32 Width, const int32 X, const int32 Y, TArray<int>& Maze);

    void DebugPrintMap(TArray<int32>& Map) const;

    void BuildLabirinth(TArray<int32>& InnerMap);
};
