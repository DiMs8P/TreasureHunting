// Fill out your copyright notice in the Description page of Project Settings.

#include "Menu/UI/THMenuHUD.h"
#include "Menu/UI/THMenuUserWidget.h"

void ATHMenuHUD::BeginPlay()
{
    Super::BeginPlay();
    if (MenuWidgetClass)
    {
        const auto MenuWidget = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);
        if (MenuWidget)
            MenuWidget->AddToViewport();
    }
}
