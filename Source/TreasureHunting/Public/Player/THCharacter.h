// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "THCharacter.generated.h"

class UCameraComponent;
class UTHSpringArmComponent;

UCLASS()
class TREASUREHUNTING_API ATHCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    ATHCharacter(const FObjectInitializer& ObjInit);

    UFUNCTION(BlueprintCallable)
    bool IsRunning() const;


protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UTHSpringArmComponent* SpringArmComponent;

public:
    // Called every frame
    //virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    void MoveForward(float Amount);
    void MoveRight(float Amount);

    void RunStart();
    void RunStop();
    
    void CameraZoomIn();
    void CameraZoomOut();

    bool WantsToRun;
};
