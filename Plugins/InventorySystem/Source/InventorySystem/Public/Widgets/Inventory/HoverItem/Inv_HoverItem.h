// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Blueprint/UserWidget.h"
#include "Inv_HoverItem.generated.h"

class UTextBlock;
class UInv_InventoryItem;
class UImage;

/**
 * The HoverItem is the item that will appear and follow the mouse
 * when an inventory item on the grid has been clicked
 */
UCLASS()
class INVENTORYSYSTEM_API UInv_HoverItem : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetImageBrush(const FSlateBrush& Brush) const;
	void UpdateStackCount(const int32 Count);

	FGameplayTag GetItemType() const;
	void SetIsStackable(bool bStacks);
	UInv_InventoryItem* GetInventoryItem() const;
	void SetInventoryItem(UInv_InventoryItem* Item);

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> Text_StackCount;

	int32 PreviousGridIndex { INDEX_NONE };
	FIntPoint GridDimensions { 0, 0 };
	TWeakObjectPtr<UInv_InventoryItem> InventoryItem;
	bool bIsStackable { false };
	int32 StackCount { 0 };

public:
	int32 GetStackCount() const { return StackCount; }
	bool IsStackable() const { return bIsStackable; }
	int32 GetPreviousIndex() const { return PreviousGridIndex; }
	void SetPreviousIndex(int32 Index) { PreviousGridIndex = Index; }
	FIntPoint GetGridDimensions() const { return GridDimensions; }
	void SetGridDimensions(const FIntPoint& Dimensions) { GridDimensions = Dimensions; }
};
