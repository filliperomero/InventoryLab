// Copyright Fillipe Romero. All Rights Reserved.

#include "Widgets/Composite/Inv_Leaf_LabeledValue.h"

#include "Components/TextBlock.h"

void UInv_Leaf_LabeledValue::NativePreConstruct()
{
	Super::NativePreConstruct();

	FSlateFontInfo FontInfoLabel = Text_Label->GetFont();
	FontInfoLabel.Size = FontSize_Label;
	
	Text_Label->SetFont(FontInfoLabel);

	FSlateFontInfo FontInfoValue = Text_Value->GetFont();
	FontInfoValue.Size = FontSize_Value;
	
	Text_Value->SetFont(FontInfoValue);
}

void UInv_Leaf_LabeledValue::SetText_Label(const FText& InText, bool bCollapse)
{
	if (bCollapse)
	{
		Text_Label->SetVisibility(ESlateVisibility::Collapsed);
		return;
	}
	
	Text_Label->SetText(InText);
}

void UInv_Leaf_LabeledValue::SetText_Value(const FText& InText, bool bCollapse)
{
	if (bCollapse)
	{
		Text_Value->SetVisibility(ESlateVisibility::Collapsed);
		return;
	}
	
	Text_Value->SetText(InText);
}
