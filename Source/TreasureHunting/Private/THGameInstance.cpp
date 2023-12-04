// Fill out your copyright notice in the Description page of Project Settings.


#include "THGameInstance.h"

#include "Kismet/GameplayStatics.h"

void UTHGameInstance::OpenMailLevel() const
{
    if (StartupGameLevel.IsNone())
    {
        UE_LOG(LogTemp, Error, TEXT("Level Name is None!"));
        return;
    }

    UGameplayStatics::OpenLevel(this, StartupGameLevel);
}
