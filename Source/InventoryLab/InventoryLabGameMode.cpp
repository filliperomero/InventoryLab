// Copyright Epic Games, Inc. All Rights Reserved.

#include "InventoryLabGameMode.h"
#include "InventoryLabCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInventoryLabGameMode::AInventoryLabGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
