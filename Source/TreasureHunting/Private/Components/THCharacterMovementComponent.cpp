// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/THCharacterMovementComponent.h"
#include "Player/THCharacter.h"

float UTHCharacterMovementComponent::GetMaxSpeed() const
{
    const float MaxSpeed = Super::GetMaxSpeed();
    const ATHCharacter* Player = Cast<ATHCharacter>(GetPawnOwner());
    return Player && Player->IsRunning() ? MaxSpeed * RunModifier : MaxSpeed;
}
