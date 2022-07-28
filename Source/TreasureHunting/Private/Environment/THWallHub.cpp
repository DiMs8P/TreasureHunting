// Fill out your copyright notice in the Description page of Project Settings.

#include "Environment/THWallHub.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "THPlayerController.h"
#include "THBaseActor.h"
#include "THCharacter.h"

ATHWallHub::ATHWallHub() {}

void ATHWallHub::BeginPlay()
{
    Super::BeginPlay();
}

void ATHWallHub::GenerateMaze()
{
    for (int i = 0; i < Actors.Num(); i++)
        Actors[i]->Destroy();
    Actors.Empty();

    TArray<int32> InnerMap;

    GetCoordsMap(InnerMap, MazeWidth, MazeLength);
    BuildLabirinth(InnerMap);
}

void ATHWallHub::BuildLabirinth(TArray<int32>& InnerMap)
{
    for (int i = 0; i < InnerMap.Num(); i++)
    {
        int32 CurLen = i / MazeWidth;
        int32 CurWidth = i % MazeWidth;
        if (InnerMap[i] == ECellType::BLOCK)
        {
            FTransform Transform = FTransform(
                FRotator::ZeroRotator, FVector(CurLen * FloorSize.X, FloorSize.Y * CurWidth, FloorSize.Z / 2 + ControlledActorSize.Z / 2));
            Actors.Add(SpawnInstance(Transform));
        }
    }
}

void ATHWallHub::GetCoordsMap(TArray<int32>& Map, const int32& Width, const int32& Lenght)
{
    FillStartCoordsMap(Map, Lenght, Width);

    FPoint StartCell = {1, 1};

    FPoint CurrentCell = StartCell;
    TArray<FPoint> Neighbours;
    TArray<FPoint> Visited;
    Map[Width * StartCell.X + StartCell.Y] = ECellType::VISITED;
    do
    {
        GetNeighbours(Lenght, Width, Map, CurrentCell, Neighbours);

        if (Neighbours.Num() == 0)
        {
            CurrentCell = Visited.Top();
            Visited.Pop();
        }
        else
        {
            Visited.Add(CurrentCell);
            CurrentCell = Neighbours[(rand() % Neighbours.Num())];
            Neighbours.Empty();
            Map[Width * CurrentCell.Y + CurrentCell.X] = ECellType::VISITED;
            MakeHole(Width, (Visited.Top().X + CurrentCell.X) / 2, (Visited.Top().Y + CurrentCell.Y) / 2, Map);
        }

    } while (Visited.Num());
}
void ATHWallHub::GetNeighbours(
    const int32 Height, const int32 Width, const TArray<int32>& Map, const FPoint StartPoint, TArray<FPoint>& Neighbors)
{
    FPoint Temp;

    if (StartPoint.X + 2 < Width && Map[Width * StartPoint.Y + (StartPoint.X + 2)] != 2)
    {
        Temp = {StartPoint.X + 2, StartPoint.Y};
        Neighbors.Add(Temp);
    }

    if (StartPoint.X - 2 >= 0 && Map[Width * StartPoint.Y + (StartPoint.X - 2)] != 2)
    {
        Temp = {StartPoint.X - 2, StartPoint.Y};
        Neighbors.Add(Temp);
    }
    if (StartPoint.Y + 2 < Height && Map[Width * (StartPoint.Y + 2) + StartPoint.X] != 2)
    {
        Temp = {StartPoint.X, StartPoint.Y + 2};
        Neighbors.Add(Temp);
    }
    if (StartPoint.Y - 2 >= 0 && Map[Width * (StartPoint.Y - 2) + StartPoint.X] != 2)
    {
        Temp = {StartPoint.X, StartPoint.Y - 2};
        Neighbors.Add(Temp);
    }
}

void ATHWallHub::MakeHole(const int32 Width, const int32 X, const int32 Y, TArray<int>& Maze)
{
    Maze[Width * Y + X] = ECellType::FREE;
}

void ATHWallHub::FillStartCoordsMap(TArray<int32>& Map, const int32& Lenght, const int32& Width)
{

    for (int i = 0; i < Lenght; i++)
    {
        for (int j = 0; j < Width; j++)
        {
            if ((i % 2 != 0 && j % 2 != 0) && (i < Lenght - 1 && j < Width - 1))
                Map.Add(ECellType::FREE);
            else
                Map.Add(ECellType::BLOCK);
        }
    }
}
