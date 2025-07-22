// Copyright Fillipe Romero. All Rights Reserved.

#include "Inv_ItemDescription.h"

#include "Components/SizeBox.h"

FVector2D UInv_ItemDescription::GetBoxSize()
{
	return SizeBox->GetDesiredSize();
}
