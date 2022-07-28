// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "THMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TREASUREHUNTING_API ATHMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
    virtual void BeginPlay() override;
};
