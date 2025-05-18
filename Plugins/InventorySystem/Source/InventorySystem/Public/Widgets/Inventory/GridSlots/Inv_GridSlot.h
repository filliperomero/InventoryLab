// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_GridSlot.generated.h"

class UImage;

UENUM(BlueprintType)
enum EInv_GridSlotState : uint8
{
	Unoccupied,
	Occupied,
	Selected,
	GrayedOut
};

UCLASS()
class INVENTORYSYSTEM_API UInv_GridSlot : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetOccupiedTexture();
	void SetUnoccupiedTexture();
	void SetSelectedTexture();
	void SetGrayedOutTexture();

private:
	int32 TileIndex;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Image_GridSlot;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	FSlateBrush Brush_Unoccupied;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	FSlateBrush Brush_Occupied;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	FSlateBrush Brush_Selected;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	FSlateBrush Brush_GrayedOut;

	EInv_GridSlotState GridSlotState { Unoccupied };
	
public:
	int32 GetTileIndex() const { return TileIndex; }
	void SetTileIndex(int32 Index) { TileIndex = Index; }
	EInv_GridSlotState GetGridSlotState() const { return GridSlotState; }
};
