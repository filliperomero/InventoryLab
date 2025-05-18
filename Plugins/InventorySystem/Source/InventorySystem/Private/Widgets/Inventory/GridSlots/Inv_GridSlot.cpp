// Copyright Fillipe Romero. All Rights Reserved.

#include "Widgets/Inventory/GridSlots/Inv_GridSlot.h"

#include "Components/Image.h"

void UInv_GridSlot::SetOccupiedTexture()
{
	GridSlotState = Occupied;
	Image_GridSlot->SetBrush(Brush_Occupied);
}

void UInv_GridSlot::SetUnoccupiedTexture()
{
	GridSlotState = Unoccupied;
	Image_GridSlot->SetBrush(Brush_Unoccupied);
}

void UInv_GridSlot::SetSelectedTexture()
{
	GridSlotState = Selected;
	Image_GridSlot->SetBrush(Brush_Selected);
}

void UInv_GridSlot::SetGrayedOutTexture()
{
	GridSlotState = GrayedOut;
	Image_GridSlot->SetBrush(Brush_GrayedOut);
}
