// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/THMainLevelHUD.h"
#include "Blueprint/UserWidget.h"

void ATHMainLevelHUD::BeginPlay()
{
    Super::BeginPlay();

    auto PlayerHudWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDWidgetClass);
    if (PlayerHudWidget)
        PlayerHudWidget->AddToViewport();
}

