// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/THMenuPlayerController.h"

void ATHMenuPlayerController::BeginPlay() {
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}