// Copyright Fillipe Romero. All Rights Reserved.

#include "Widgets/Composite/Inv_Leaf_Image.h"

#include "Components/Image.h"
#include "Components/SizeBox.h"

void UInv_Leaf_Image::SetImage(UTexture2D* InTexture) const
{
	Image_Icon->SetBrushFromTexture(InTexture);
}

void UInv_Leaf_Image::SetBoxSize(const FVector2D& InSize) const
{
	SizeBox_Icon->SetWidthOverride(InSize.X);
	SizeBox_Icon->SetHeightOverride(InSize.Y);
}

void UInv_Leaf_Image::SetImageSize(const FVector2D& InSize) const
{
	Image_Icon->SetDesiredSizeOverride(InSize);
}

FVector2D UInv_Leaf_Image::GetImageSize() const
{
	return Image_Icon->GetDesiredSize();
}
