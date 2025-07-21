// Copyright Fillipe Romero. All Rights Reserved.

#include "Items/Fragments/Inv_ItemFragment.h"

void FInv_HealthPotionFragment::OnConsume(APlayerController* PlayerController)
{
	/// Get a stats component from the PlayerController or the PlayerController->GetPawn()
	/// or get the ability System Component and apply a Gameplay Effect
	/// or call an interface function for Healing()
	/// P.S.: This will be called in the server, so make sure affected variables are replicated and/or RPC's are called

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Potion Consumed! Healing by %f"), HealAmount));
}

void FInv_ManaPotionFragment::OnConsume(APlayerController* PlayerController)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Mana Potion Consumed! Mana replenishment by %f"), ManaAmount));
}
