// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/THCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/THCharacterMovementComponent.h"
#include "Components/THSpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ATHCharacter::ATHCharacter(const FObjectInitializer& ObjInit)
    : Super(ObjInit.SetDefaultSubobjectClass<UTHCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<UTHSpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void ATHCharacter::BeginPlay()
{
    //SetStartPosition();
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
        PlayerInputComponent->BindAction("ZoomIn", IE_Pressed, this, &ATHCharacter::CameraZoomIn);
        PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &ATHCharacter::CameraZoomOut);
        PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATHCharacter::Jump);
        PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ATHCharacter::RunStart);
        PlayerInputComponent->BindAction("Run", IE_Released, this, &ATHCharacter::RunStop);
    }
}


void ATHCharacter::CameraZoomIn()
{
    if (SpringArmComponent->TargetArmLength <= SpringArmComponent->GetArmMinLenght())
        return;
    SpringArmComponent->TargetArmLength = SpringArmComponent->TargetArmLength - SpringArmComponent->GetArmClampValue();
}
void ATHCharacter::CameraZoomOut()
{
    if (SpringArmComponent->TargetArmLength >= SpringArmComponent->GetArmMaxLenght())
        return;
    SpringArmComponent->TargetArmLength = SpringArmComponent->TargetArmLength + SpringArmComponent->GetArmClampValue();
}

void ATHCharacter::RunStart()
{
    WantsToRun = true;
}

void ATHCharacter::RunStop()
{
    WantsToRun = false;
}

bool ATHCharacter::IsRunning() const
{
    return WantsToRun && !GetVelocity().IsZero();
}