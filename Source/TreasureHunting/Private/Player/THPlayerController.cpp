// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/THPlayerController.h"
#include "Player/THCharacter.h"

void ATHPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    InputComponent->BindAction("ShowLevelUI", IE_Pressed, this, &ATHPlayerController::ShowUI);
}

void ATHPlayerController::BeginPlay()
{
    Super::BeginPlay();
}

void ATHPlayerController::ShowUI()
{
    bShowMouseCursor = true;
    SetInputMode(FInputModeUIOnly());
}