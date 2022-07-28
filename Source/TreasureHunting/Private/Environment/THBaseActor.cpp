// Fill out your copyright notice in the Description page of Project Settings.

#include "Environment/THBaseActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATHBaseActor::ATHBaseActor()
{
    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
    SetRootComponent(StaticMeshComponent);
}

// Called when the game starts or when spawned
void ATHBaseActor::BeginPlay()
{
    Super::BeginPlay();
    check(StaticMeshComponent);
    ActorSize = StaticMeshComponent->GetStaticMesh()->GetBounds().BoxExtent * 2 * StaticMeshComponent->GetRelativeScale3D();
}

FVector ATHBaseActor::GetActorSize() const
{
    return ActorSize;
}