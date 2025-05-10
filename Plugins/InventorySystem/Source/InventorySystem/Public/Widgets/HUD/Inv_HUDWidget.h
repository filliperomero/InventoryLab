// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_HUDWidget.generated.h"

UCLASS()
class INVENTORYSYSTEM_API UInv_HUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory System")
	void ShowPickupMessage(const FString& Message);

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory System")
	void HidePickupMessage();
};
