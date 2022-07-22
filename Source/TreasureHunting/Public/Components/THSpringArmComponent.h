// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "THSpringArmComponent.generated.h"

/**
 *
 */
UCLASS()
class TREASUREHUNTING_API UTHSpringArmComponent : public USpringArmComponent
{
    GENERATED_BODY()
public:
    float GetArmClampValue() const { return ArmClampValue; }

    float GetArmMinLenght() const { return ArmMinLenght; }

    float GetArmMaxLenght() const { return ArmMaxLenght; }

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components", meta = (ClampMin = 20.0f, ClampMax = 500.0f))
    float ArmClampValue = 50.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components", meta = (ClampMin = 100.0f, ClampMax = 500.0f))
    float ArmMinLenght = 300.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components", meta = (ClampMin = 1000.0f, ClampMax = 5000.0f))
    float ArmMaxLenght = 2000.0f;


};
