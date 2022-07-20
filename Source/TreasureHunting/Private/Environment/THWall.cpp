// Fill out your copyright notice in the Description page of Project Settings.


#include "Environment/THWall.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATHWall::ATHWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
    SetRootComponent(StaticMeshComponent);

}

// Called when the game starts or when spawned
void ATHWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATHWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

