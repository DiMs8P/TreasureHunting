// Fill out your copyright notice in the Description page of Project Settings.


#include "Environment/THFloorHub.h"

ATHFloorHub::ATHFloorHub()
{

}

void ATHFloorHub::BeginPlay()
{
	Super::BeginPlay();
}

void ATHFloorHub::InitMazeFloor() const
{
    UWorld* World = GetWorld();
    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("Can't get a World pointer!"))
        checkNoEntry();
    }

    for (int i = 0; i < MazeWidth; i++)
    {
        for (int j = 0; j < MazeLength; j++)
        {
            const FTransform Transform =
                FTransform(FRotator::ZeroRotator, FVector(ControlledActorSize.X * j, ControlledActorSize.Y * i, 0));
            SpawnInstance(Transform);
        }
    }
}

