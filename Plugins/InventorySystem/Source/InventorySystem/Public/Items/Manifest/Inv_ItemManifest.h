// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Types/Inv_GridTypes.h"
#include "StructUtils/InstancedStruct.h"

#include "Inv_ItemManifest.generated.h"

class UInv_InventoryItem;

/**
 * The Item Manifest contains all the necessary data for creating a new Inventory Item
 */

USTRUCT(BlueprintType)
struct INVENTORYSYSTEM_API FInv_ItemManifest
{
	GENERATED_BODY()
	
	UInv_InventoryItem* Manifest(UObject* NewOuter);
	EInv_ItemCategory GetItemCategory() const { return ItemCategory; }
	FGameplayTag GetItemType() const { return ItemType; }

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System")
	EInv_ItemCategory ItemCategory { EInv_ItemCategory::None };
	
	UPROPERTY(EditAnywhere, Category = "Inventory System", meta=(Categories="GameItems"))
	FGameplayTag ItemType;
};
