// Copyright Fillipe Romero. All Rights Reserved.

#include "Widgets/Utils/Inv_WidgetUtils.h"

#include "Blueprint/SlateBlueprintLibrary.h"
#include "Components/Widget.h"

FVector2D UInv_WidgetUtils::GetWidgetPosition(UWidget* Widget)
{
	const FGeometry Geometry = Widget->GetCachedGeometry();
	FVector2D OutPixelPosition;
	FVector2D OutViewportPosition;

	USlateBlueprintLibrary::LocalToViewport(Widget, Geometry, USlateBlueprintLibrary::GetLocalTopLeft(Geometry), OutPixelPosition, OutViewportPosition);
	
	return OutViewportPosition;
}

int32 UInv_WidgetUtils::GetIndexFromPosition(const FIntPoint& Position, const int32 Columns)
{
	return Position.X + Position.Y * Columns;
}

FIntPoint UInv_WidgetUtils::GetPositionFromIndex(const int32 Index, const int32 Columns)
{
	return FIntPoint(Index % Columns, Index / Columns);
}
