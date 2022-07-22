// Copyright Epic Games, Inc. All Rights Reserved.


#include "TreasureHuntingGameModeBase.h"
#include "Player/THCharacter.h"
#include "UI/THMainLevelHUD.h"

ATreasureHuntingGameModeBase::ATreasureHuntingGameModeBase() {
    DefaultPawnClass = ATHCharacter::StaticClass();
    HUDClass = ATHMainLevelHUD::StaticClass();
}

