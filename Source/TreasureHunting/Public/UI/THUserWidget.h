// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "THUserWidget.generated.h"

class UButton;

UCLASS()
class TREASUREHUNTING_API UTHUserWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    virtual bool Initialize() override;

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* GenMazeButton;


private:
    UFUNCTION()
    void OnInitMaze();
};
