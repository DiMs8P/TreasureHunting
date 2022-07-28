// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "THPlayerController.generated.h"

UCLASS()
class TREASUREHUNTING_API ATHPlayerController : public APlayerController
{
    GENERATED_BODY()
public:
    virtual void SetupInputComponent() override;
    virtual void BeginPlay() override;

    void ChangeInputUI();

   // void SetInputUIState(bool NewState) { InputUIActive = NewState; }

private:
    bool InputUIActive = true;
};
