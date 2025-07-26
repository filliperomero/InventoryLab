// Copyright Fillipe Romero. All Rights Reserved.

#include "Widgets/Composite/Inv_Leaf_Text.h"

#include "Components/TextBlock.h"

void UInv_Leaf_Text::NativePreConstruct()
{
	Super::NativePreConstruct();

	FSlateFontInfo FontInfo = Text_LeafText->GetFont();
	FontInfo.Size = FontSize;

	Text_LeafText->SetFont(FontInfo);
}

void UInv_Leaf_Text::SetText(const FText& InText)
{
	Text_LeafText->SetText(InText);
}
