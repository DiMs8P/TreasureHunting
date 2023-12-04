// Fill out your copyright notice in the Description page of Project Settings.

#include "Menu/UI/THMenuUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "THGameInstance.h"

bool UTHMenuUserWidget::Initialize()
{
    const auto InitStatus = Super::Initialize();
    if (InitStatus && StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &UTHMenuUserWidget::OnStartGame);
    }
    return InitStatus;
}

void UTHMenuUserWidget::OnStartGame() {
    if (!GetWorld())
    {
        return;
    }

    const auto THGameInstance = GetWorld()->GetGameInstance<UTHGameInstance>();
    if (!THGameInstance)
    {
        return;
    }

    THGameInstance->OpenMailLevel();
}