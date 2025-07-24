// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Composite/Inv_Composite.h"
#include "Inv_ItemDescription.generated.h"

class USizeBox;

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInv_ItemDescription : public UInv_Composite
{
	GENERATED_BODY()

public:
	FVector2D GetBoxSize();

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USizeBox> SizeBox;
};
