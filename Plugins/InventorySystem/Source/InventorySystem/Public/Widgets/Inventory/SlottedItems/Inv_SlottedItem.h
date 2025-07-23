// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_SlottedItem.generated.h"

class UTextBlock;
class UInv_InventoryItem;
class UImage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSlottedItemClicked, int32, GridIndex, const FPointerEvent&, MouseEvent);

UCLASS()
class INVENTORYSYSTEM_API UInv_SlottedItem : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
	
	void SetImageBrush(const FSlateBrush& Brush) const;
	void SetInventoryItem(UInv_InventoryItem* Item);
	void UpdateStackCount(const int32 StackCount);

	/** Delegates */
	FSlottedItemClicked OnSlottedItemClicked;

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> Text_StackCount;

	int32 GridIndex { INDEX_NONE };
	FIntPoint GridDimensions { 0, 0 };
	TWeakObjectPtr<UInv_InventoryItem> InventoryItem;
	bool bIsStackable { false };

public:
	bool IsStackable() const { return bIsStackable; }
	void SetIsStackable(bool bStackable) { bIsStackable = bStackable; }
	UImage* GetImageIcon() const { return Image_Icon; }
	void SetGridIndex(int32 Index) { GridIndex = Index; }
	int32 GetGridIndex() const { return GridIndex; }
	void SetGridDimensions(const FIntPoint& Dimensions) { GridDimensions = Dimensions; }
	FIntPoint GetGridDimensions() const { return GridDimensions; }
	UInv_InventoryItem* GetInventoryItem() const { return InventoryItem.Get(); }
};
