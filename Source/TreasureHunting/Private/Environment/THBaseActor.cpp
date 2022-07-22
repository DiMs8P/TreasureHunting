// Fill out your copyright notice in the Description page of Project Settings.

#include "Environment/THBaseActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATHBaseActor::ATHBaseActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

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

// Called every frame
void ATHBaseActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
FVector ATHBaseActor::GetActorSize() const
{
    return ActorSize;
}