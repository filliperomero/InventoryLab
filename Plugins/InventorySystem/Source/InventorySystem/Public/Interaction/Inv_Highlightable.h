// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Inv_Highlightable.generated.h"

UINTERFACE()
class UInv_Highlightable : public UInterface
{
	GENERATED_BODY()
};

class INVENTORYSYSTEM_API IInv_Highlightable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category = "Inventory System")
	void Highlight();

	UFUNCTION(BlueprintNativeEvent, Category = "Inventory System")
	void UnHighlight();
};
