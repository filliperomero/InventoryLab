// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Inv_SlottedItem.h"
#include "Inv_EquippedSlottedItem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEquippedSlottedItemClicked, class UInv_EquippedSlottedItem*, SlottedItem);

UCLASS()
class INVENTORYSYSTEM_API UInv_EquippedSlottedItem : public UInv_SlottedItem
{
	GENERATED_BODY()

public:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	
	FGameplayTag GetEquipmentItemTag() const { return EquipmentTypeTag; }
	void SetEquipmentTypeTag(const FGameplayTag& InTag) { EquipmentTypeTag = InTag; }

	FEquippedSlottedItemClicked OnEquippedSlottedItemClicked;

private:
	UPROPERTY()
	FGameplayTag EquipmentTypeTag;
};
