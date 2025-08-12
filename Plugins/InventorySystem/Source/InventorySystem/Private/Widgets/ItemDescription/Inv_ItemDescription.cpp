// Copyright Fillipe Romero. All Rights Reserved.

#include "Widgets/ItemDescription/Inv_ItemDescription.h"

#include "Components/SizeBox.h"

FVector2D UInv_ItemDescription::GetBoxSize()
{
	return SizeBox->GetDesiredSize();
}

void UInv_ItemDescription::SetVisibility(ESlateVisibility InVisibility)
{
	for (const auto Child : GetChildren())
	{
		Child->Collapse();
	}
	
	Super::SetVisibility(InVisibility);
}
