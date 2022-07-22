// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/THUserWidget.h"
#include "Components/Button.h"
#include "EnvironmentHUBActor.h"
#include "Player/THCharacter.h"
#include "Player/THPlayerController.h"
#include "Kismet/GameplayStatics.h"

bool UTHUserWidget::Initialize() {
    const auto InitStatus = Super::Initialize();

    if (GenMazeButton)
    {
        GenMazeButton->OnClicked.AddDynamic(this, &UTHUserWidget::GenerateMaze);
    }
    return InitStatus;
}


void UTHUserWidget::GenerateMaze() {
    const auto Player = Cast<ATHCharacter>(GetOwningPlayerPawn());
    const auto Controller = Cast<ATHPlayerController>(Player->GetController());
    Controller->SetInputMode(FInputModeGameOnly());
    Controller->bShowMouseCursor = false;
    AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), AEnvironmentHUBActor::StaticClass());
    const auto CurrentEnvironmentHUBActor = Cast<AEnvironmentHUBActor>(FoundActor);
    if (!CurrentEnvironmentHUBActor)
        return;
    CurrentEnvironmentHUBActor->GenerateMaze();
}
