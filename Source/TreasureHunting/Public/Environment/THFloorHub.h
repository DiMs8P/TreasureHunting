// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "THBaseEnvironmentHUBActor.h"
#include "THFloorHub.generated.h"

UCLASS()
class TREASUREHUNTING_API ATHFloorHub : public ATHBaseEnvironmentHUBActor
{
	GENERATED_BODY()
	
public:	
	ATHFloorHub();
    void InitMazeFloor() const;

protected:
	virtual void BeginPlay() override;

};
