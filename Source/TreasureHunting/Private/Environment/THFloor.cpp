// Fill out your copyright notice in the Description page of Project Settings.

#include "Environment/THFloor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATHFloor::ATHFloor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
    SetRootComponent(StaticMeshComponent);
}

// Called when the game starts or when spawned
void ATHFloor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ATHFloor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
