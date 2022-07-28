// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "THMenuUserWidget.generated.h"

class UButton;

UCLASS()
class TREASUREHUNTING_API UTHMenuUserWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    virtual bool Initialize() override;

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* StartGameButton;

private:
    UFUNCTION()
    void OnStartGame();
};
