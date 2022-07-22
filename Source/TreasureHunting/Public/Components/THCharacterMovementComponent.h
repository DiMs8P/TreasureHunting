// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "THCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class TREASUREHUNTING_API UTHCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
public:
    virtual float GetMaxSpeed() const override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = 1.5f, ClampMax = 10.0f))
    float RunModifier = 2.0f;
};
