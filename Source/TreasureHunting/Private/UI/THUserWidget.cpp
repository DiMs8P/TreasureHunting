// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/THUserWidget.h"
#include "Components/Button.h"
#include "THEnvironmentHubActor.h"
#include "Player/THCharacter.h"
#include "Player/THPlayerController.h"
#include "Kismet/GameplayStatics.h"

bool UTHUserWidget::Initialize()
{
    const auto InitStatus = Super::Initialize();

    if (GenMazeButton)
    {
        GenMazeButton->OnClicked.AddDynamic(this, &UTHUserWidget::OnInitMaze);
    }
    return InitStatus;
}

void UTHUserWidget::OnInitMaze()
{
    const auto Player = Cast<ATHCharacter>(GetOwningPlayerPawn());
    const auto Controller = Cast<ATHPlayerController>(Player->GetController());
    if (!Controller)
        return;
    Controller->ChangeInputUI();

    AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), ATHEnvironmentHubActor::StaticClass());
    const auto CurrentEnvironmentHUBActor = Cast<ATHEnvironmentHubActor>(FoundActor);

    if (!CurrentEnvironmentHUBActor)
        return;
    CurrentEnvironmentHUBActor->GenerateMaze();
}