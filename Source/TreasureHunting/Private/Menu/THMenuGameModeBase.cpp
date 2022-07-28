// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/THMenuGameModeBase.h"
#include "Menu/THMenuPlayerController.h"
#include "Menu/UI/THMenuHUD.h"

ATHMenuGameModeBase::ATHMenuGameModeBase()
{
    PlayerControllerClass = ATHMenuPlayerController::StaticClass();
    HUDClass = ATHMenuHUD::StaticClass();
}