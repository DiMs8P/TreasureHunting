// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup/THTrophyActor.h"
#include "THCharacter.h"
#include "Components/SphereComponent.h"

// Sets default values
ATHTrophyActor::ATHTrophyActor()
{
    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(50.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    SetRootComponent(CollisionComponent);

    StaticMeshComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ATHTrophyActor::BeginPlay()
{
    Super::BeginPlay();
}

void ATHTrophyActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    const auto Character = Cast<ATHCharacter>(OtherActor);
    if (Character)
    {
        Destroy();
        FGenericPlatformMisc::RequestExit(false);
    }
}
