// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup/THTrophyActor.h"
#include "THCharacter.h"
#include "THGameInstance.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

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

    if (const auto Character = Cast<ATHCharacter>(OtherActor))
    {
        Destroy();
        if (!GetWorld())
        {
            return;
        }

        const auto THGameInstance = GetWorld()->GetGameInstance<UTHGameInstance>();
        if (!THGameInstance)
        {
            return;
        }

        THGameInstance->OpenMailLevel();
    }
}
