// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/THPlayerController.h"
#include "Player/THCharacter.h"

void ATHPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    InputComponent->BindAction("ChangeInputUI", IE_Pressed, this, &ATHPlayerController::ChangeInputUI);
}

void ATHPlayerController::BeginPlay()
{
    Super::BeginPlay();
    SetInputMode(FInputModeGameOnly());
}

void ATHPlayerController::ChangeInputUI()
{
    if (InputUIActive)
    {
        bShowMouseCursor = true;
        InputUIActive = false;
    }
    else
    {
        bShowMouseCursor = false;
        InputUIActive = true;
    }
}