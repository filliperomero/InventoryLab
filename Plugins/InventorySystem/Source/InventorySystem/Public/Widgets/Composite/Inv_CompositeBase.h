// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Blueprint/UserWidget.h"
#include "Inv_CompositeBase.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInv_CompositeBase : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void Collapse();
	void Expand();

	// The use of "using" is basically creating an "alias". So FuncType means w/e we put after "="
	using FuncType = TFunction<void(UInv_CompositeBase*)>;
	virtual void ApplyFunction(FuncType Function) {}

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System", meta=(Categories="FragmentTags"))
	FGameplayTag FragmentTag;

public:
	FGameplayTag GetFragmentTag() const { return FragmentTag; }
	void SetFragmentTag(const FGameplayTag InTag) { FragmentTag = InTag; }
};
