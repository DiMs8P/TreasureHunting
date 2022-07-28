// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Environment/THBaseActor.h"
#include "THTrophyActor.generated.h"

class USphereComponent;

UCLASS()
class TREASUREHUNTING_API ATHTrophyActor : public ATHBaseActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ATHTrophyActor();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USphereComponent* CollisionComponent;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
