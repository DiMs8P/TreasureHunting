// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "THMainLevelHUD.generated.h"

UCLASS()
class TREASUREHUNTING_API ATHMainLevelHUD : public AHUD{
	GENERATED_BODY()

protected:

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

    virtual void BeginPlay() override;
};
