// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/Inv_GridTypes.h"
#include "Inv_InventoryGrid.generated.h"

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

private:
	TWeakObjectPtr<UInv_InventoryComponent> InventoryComponent;
	
	void ConstructGrid();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory System", meta=(AllowPrivateAccess = "true"))
	EInv_ItemCategory ItemCategory;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCanvasPanel> CanvasPanel;

	UPROPERTY()
	TArray<TObjectPtr<UInv_GridSlot>> GridSlots;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	TSubclassOf<UInv_GridSlot> GridSlotClass;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	int32 Rows { 4 };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	int32 Columns { 8};

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	float TileSize { 54.f };

	bool MatchesCategory(const UInv_InventoryItem* Item) const;

public:
	EInv_ItemCategory GetItemCategory() const { return ItemCategory; }
};
