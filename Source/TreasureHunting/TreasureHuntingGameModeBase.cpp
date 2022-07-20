// Copyright Epic Games, Inc. All Rights Reserved.


#include "TreasureHuntingGameModeBase.h"
#include "Player/THCharacter.h"

ATreasureHuntingGameModeBase::ATreasureHuntingGameModeBase() {
    DefaultPawnClass = ATHCharacter::StaticClass();
}

