// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "THGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TREASUREHUNTING_API UTHGameInstance : public UGameInstance
{
    GENERATED_BODY()
public:
    void OpenMailLevel() const;
    
    FName GetStartupGameLevelName() const { return StartupGameLevel; }

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FName StartupGameLevel = NAME_None;

};
