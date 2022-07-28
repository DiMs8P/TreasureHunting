// Fill out your copyright notice in the Description page of Project Settings.


#include "Environment/THBaseEnvironmentHUBActor.h"
#include "Environment/THBaseActor.h"

// Sets default values
ATHBaseEnvironmentHUBActor::ATHBaseEnvironmentHUBActor()
{
}

// Called when the game starts or when spawned
void ATHBaseEnvironmentHUBActor::BeginPlay()
{
	Super::BeginPlay();
}

void ATHBaseEnvironmentHUBActor::Init(int32 InitMazeWidth, int32 InitMazeLength)
{
    UWorld* World = GetWorld();
    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("Can't get a World pointer!"))
        checkNoEntry();
    }
    if (!ControlledActor)
    {
        UE_LOG(LogTemp, Error, TEXT("You forgot to set a base actor"))
        checkNoEntry();
    }

    const auto Instance =
        World->SpawnActor<ATHBaseActor>(ControlledActor, FTransform(FRotator::ZeroRotator, FVector(2000, 2000, 2000)));

    if (!Instance)
    {
        UE_LOG(LogTemp, Error, TEXT("Actor didn't spawned"))
        ControlledActorSize = FVector::ZeroVector;
    }

    ControlledActorSize = Instance->GetActorSize();
    Instance->Destroy();

    MazeWidth = InitMazeWidth;
    MazeLength = InitMazeLength;
}

ATHBaseActor* ATHBaseEnvironmentHUBActor::SpawnInstance(const FTransform& Transform) const
{
    UWorld* World = GetWorld();

    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("Can't get a World pointer!"))
        checkNoEntry();
    }
    if (!ControlledActor)
    {
        UE_LOG(LogTemp, Error, TEXT("You forgot to set a base actor"))
        checkNoEntry();
    }

    const auto Instance = World->SpawnActorDeferred<ATHBaseActor>(ControlledActor, Transform);
    Instance->FinishSpawning(Transform);
    return Instance;
}