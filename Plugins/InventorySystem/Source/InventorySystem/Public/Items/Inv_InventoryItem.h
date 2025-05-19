// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Items/Manifest/Inv_ItemManifest.h"

#include "Inv_InventoryItem.generated.h"

UCLASS()
class INVENTORYSYSTEM_API UInv_InventoryItem : public UObject
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual bool IsSupportedForNetworking() const override { return true; }

	void SetItemManifest(const FInv_ItemManifest& Manifest);
	bool IsStackable() const;

private:
	UPROPERTY(VisibleAnywhere, Category = "Inventory System", meta=(BaseStruct="/Script/InventorySystem.Inv_ItemManifest"), Replicated)
	FInstancedStruct ItemManifest;

public:
	const FInv_ItemManifest& GetItemManifest() const { return ItemManifest.Get<FInv_ItemManifest>(); }
	FInv_ItemManifest& GetItemManifestMutable() { return ItemManifest.GetMutable<FInv_ItemManifest>(); }
};

template <typename FragmentType>
const FragmentType* GetFragment(const UInv_InventoryItem* InventoryItem, const FGameplayTag& FragmentTag)
{
	if (!IsValid(InventoryItem) || !FragmentTag.IsValid()) return nullptr;

	const FInv_ItemManifest& Manifest = InventoryItem->GetItemManifest();

	return Manifest.GetFragmentOfTypeWithTag<FragmentType>(FragmentTag);
}
