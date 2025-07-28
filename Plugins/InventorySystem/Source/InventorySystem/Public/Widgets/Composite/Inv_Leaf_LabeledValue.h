// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Inv_Leaf.h"
#include "Inv_Leaf_LabeledValue.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInv_Leaf_LabeledValue : public UInv_Leaf
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;
	void SetText_Label(const FText& InText, bool bCollapse);
	void SetText_Value(const FText& InText, bool bCollapse);

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> Text_Label;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> Text_Value;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	int32 FontSize_Label { 12 };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	int32 FontSize_Value { 18 };
};
