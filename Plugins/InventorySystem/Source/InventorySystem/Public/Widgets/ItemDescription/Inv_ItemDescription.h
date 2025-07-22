// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_ItemDescription.generated.h"

class USizeBox;

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInv_ItemDescription : public UUserWidget
{
	GENERATED_BODY()

public:
	FVector2D GetBoxSize();

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USizeBox> SizeBox;
};
