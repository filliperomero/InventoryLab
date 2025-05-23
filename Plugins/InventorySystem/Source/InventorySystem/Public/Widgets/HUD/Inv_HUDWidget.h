﻿// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_HUDWidget.generated.h"

class UInv_InfoMessage;

UCLASS()
class INVENTORYSYSTEM_API UInv_HUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory System")
	void ShowPickupMessage(const FString& Message);

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory System")
	void HidePickupMessage();

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UInv_InfoMessage> InfoMessage;

	UFUNCTION()
	void OnNoInventoryRoom();
};
