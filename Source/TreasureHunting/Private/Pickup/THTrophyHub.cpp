// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup/THTrophyHub.h"
#include "THBaseActor.h"


int32 ATHTrophyHub::MakeRandomOddNumber(int32 Min, int32 Max) const
{
    int32 TempMin = Min / 2;
    int32 TempMax = Max / 2 - 1;
    int32 RandOddInt = FMath::RandRange(TempMin, TempMax);
    RandOddInt = (RandOddInt * 2) + 1;
    return RandOddInt;
}

void ATHTrophyHub::SpawnChest(FTransform Transform) {
    if (ChestActor)
    {
        ChestActor->Destroy();
    }
    ChestActor = SpawnInstance(Transform);
    ChestActor->SetActorLocation(Transform.GetLocation());
}
