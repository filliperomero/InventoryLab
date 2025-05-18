// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/Inv_GridTypes.h"
#include "Inv_InventoryGrid.generated.h"

struct FInv_ImageFragment;
struct FInv_GridFragment;
class UInv_SlottedItem;
struct FInv_ItemManifest;
class UInv_ItemComponent;
class UInv_InventoryComponent;
class UCanvasPanel;
class UInv_GridSlot;

UCLASS()
class INVENTORYSYSTEM_API UInv_InventoryGrid : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void AddItem(UInv_InventoryItem* Item);

	FInv_SlotAvailabilityResult HasRoomForItem(const UInv_ItemComponent* ItemComponent);
private:
	TWeakObjectPtr<UInv_InventoryComponent> InventoryComponent;
	
	void ConstructGrid();
	FInv_SlotAvailabilityResult HasRoomForItem(const UInv_InventoryItem* InventoryItem);
	FInv_SlotAvailabilityResult HasRoomForItem(const FInv_ItemManifest& Manifest);
	void AddItemToIndices(const FInv_SlotAvailabilityResult& Result, UInv_InventoryItem* NewItem);
	void AddItemToIndex(UInv_InventoryItem* Item, const int32 Index, const bool bStackable, const int32 StackSize);
	UInv_SlottedItem* CreateSlottedItem(UInv_InventoryItem* Item, const bool bStackable, const int32 StackSize, const FInv_GridFragment* GridFragment, const FInv_ImageFragment* ImageFragment, const int32 Index);
	bool MatchesCategory(const UInv_InventoryItem* Item) const;
	FVector2D GetDrawSize(const FInv_GridFragment* GridFragment) const;
	void SetSlottedItemImage(const UInv_SlottedItem* SlottedItem, const FInv_GridFragment* GridFragment, const FInv_ImageFragment* ImageFragment) const;
	void AddSlottedItemToCanvas(const int32 Index, const FInv_GridFragment* GridFragment, UInv_SlottedItem* SlottedItem) const;
	void UpdateGridSlots(UInv_InventoryItem* NewItem, const int32 Index);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory System", meta=(AllowPrivateAccess = "true"))
	EInv_ItemCategory ItemCategory;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCanvasPanel> CanvasPanel;

	UPROPERTY()
	TArray<TObjectPtr<UInv_GridSlot>> GridSlots;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	TSubclassOf<UInv_GridSlot> GridSlotClass;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	TSubclassOf<UInv_SlottedItem> SlottedItemClass;

	UPROPERTY()
	TMap<int32, TObjectPtr<UInv_SlottedItem>> SlottedItems;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	int32 Rows { 4 };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	int32 Columns { 8 };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	float TileSize { 54.f };
public:
	EInv_ItemCategory GetItemCategory() const { return ItemCategory; }
};
