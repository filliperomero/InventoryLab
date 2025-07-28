// Copyright Fillipe Romero. All Rights Reserved.

#include "Items/Fragments/Inv_ItemFragment.h"

#include "Widgets/Composite/Inv_CompositeBase.h"
#include "Widgets/Composite/Inv_Leaf_Image.h"
#include "Widgets/Composite/Inv_Leaf_LabeledValue.h"
#include "Widgets/Composite/Inv_Leaf_Text.h"

void FInv_InventoryItemFragment::Assimilate(UInv_CompositeBase* Composite) const
{
	if (!MatchesWidgetTag(Composite)) return;
	
	Composite->Expand();
}

bool FInv_InventoryItemFragment::MatchesWidgetTag(const UInv_CompositeBase* Composite) const
{
	return Composite->GetFragmentTag().MatchesTagExact(GetFragmentTag());
}

void FInv_ImageFragment::Assimilate(UInv_CompositeBase* Composite) const
{
	FInv_InventoryItemFragment::Assimilate(Composite);
	if (!MatchesWidgetTag(Composite)) return;

	UInv_Leaf_Image* Image = Cast<UInv_Leaf_Image>(Composite);
	if (!IsValid(Image)) return;

	Image->SetImage(Icon);
	Image->SetBoxSize(IconDimensions);
	Image->SetImageSize(IconDimensions);
}

void FInv_TextFragment::Assimilate(UInv_CompositeBase* Composite) const
{
	FInv_InventoryItemFragment::Assimilate(Composite);
	if (!MatchesWidgetTag(Composite)) return;

	UInv_Leaf_Text* LeafText = Cast<UInv_Leaf_Text>(Composite);
	if (!IsValid(LeafText)) return;

	LeafText->SetText(FragmentText);
}

void FInv_LabeledNumberFragment::Assimilate(UInv_CompositeBase* Composite) const
{
	FInv_InventoryItemFragment::Assimilate(Composite);
	if (!MatchesWidgetTag(Composite)) return;

	UInv_Leaf_LabeledValue* LeafLabeledValue = Cast<UInv_Leaf_LabeledValue>(Composite);
	if (!IsValid(LeafLabeledValue)) return;

	LeafLabeledValue->SetText_Label(Text_Label, bCollapseLabel);

	FNumberFormattingOptions FormattingOptions;
	FormattingOptions.MinimumFractionalDigits = MinFractionalDigits;
	FormattingOptions.MaximumFractionalDigits = MaxFractionalDigits;
	
	LeafLabeledValue->SetText_Value(FText::AsNumber(Value, &FormattingOptions), bCollapseValue);
}

void FInv_LabeledNumberFragment::Manifest()
{
	FInv_InventoryItemFragment::Manifest();

	if (bRandomizeOnManifest)
	{
		Value = FMath::FRandRange(MinValue, MaxValue);
		bRandomizeOnManifest = false;
	}
}

void FInv_ConsumableFragment::Assimilate(UInv_CompositeBase* Composite) const
{
	FInv_InventoryItemFragment::Assimilate(Composite);

	for (const auto& Modifier : ConsumeModifiers)
	{
		const auto& ModifierRef = Modifier.Get();
		ModifierRef.Assimilate(Composite);
	}
}

void FInv_ConsumableFragment::OnConsume(APlayerController* PlayerController)
{
	for (auto& Modifier : ConsumeModifiers)
	{
		auto& ModifierRef = Modifier.GetMutable();
		ModifierRef.OnConsume(PlayerController);
	}
}

void FInv_ConsumableFragment::Manifest()
{
	FInv_InventoryItemFragment::Manifest();

	for (auto& Modifier : ConsumeModifiers)
	{
		auto& ModifierRef = Modifier.GetMutable();
		ModifierRef.Manifest();
	}
}

void FInv_HealthPotionFragment::OnConsume(APlayerController* PlayerController)
{
	/// Get a stats component from the PlayerController or the PlayerController->GetPawn()
	/// or get the ability System Component and apply a Gameplay Effect
	/// or call an interface function for Healing()
	/// P.S.: This will be called in the server, so make sure affected variables are replicated and/or RPC's are called

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Potion Consumed! Healing by %f"), GetValue()));
}

void FInv_ManaPotionFragment::OnConsume(APlayerController* PlayerController)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Mana Potion Consumed! Mana replenishment by %f"), GetValue()));
}
