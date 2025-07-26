// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Inv_Leaf.h"
#include "Inv_Leaf_Text.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInv_Leaf_Text : public UInv_Leaf
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;
	void SetText(const FText& InText);

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> Text_LeafText;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	int32 FontSize { 12 };
};
