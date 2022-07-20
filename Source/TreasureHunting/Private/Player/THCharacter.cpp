// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/THCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ATHCharacter::ATHCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);

}

// Called when the game starts or when spawned
void ATHCharacter::BeginPlay()
{

    check(CameraComponent);
    check(SpringArmComponent);
    Super::BeginPlay();
}

// Called every frame
void ATHCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATHCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    if (PlayerInputComponent)
    {
        PlayerInputComponent->BindAxis("MoveForward", this, &ATHCharacter::MoveForward);
        PlayerInputComponent->BindAxis("MoveRight", this, &ATHCharacter::MoveRight);
        PlayerInputComponent->BindAxis("ZoomUp", this, &ATHCharacter::ZoomUp);
        PlayerInputComponent->BindAxis("ZoomDown", this, &ATHCharacter::ZoomDown);
    }
}

void ATHCharacter::MoveForward(float Amount)
{
    if (Amount == 0.0f)
        return;
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ATHCharacter::MoveRight(float Amount)
{
    if (Amount == 0.0f)
        return;
    AddMovementInput(GetActorRightVector(), Amount);
}

void ATHCharacter::ZoomUp(float Amount)
{
    SpringArmComponent->TargetArmLength += Amount;
}

void ATHCharacter::ZoomDown(float Amount)
{
    SpringArmComponent->TargetArmLength -= Amount;
}