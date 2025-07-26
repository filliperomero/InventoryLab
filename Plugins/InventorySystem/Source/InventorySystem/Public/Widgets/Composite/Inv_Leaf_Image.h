// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Inv_Leaf.h"
#include "Inv_Leaf_Image.generated.h"

class USizeBox;
class UImage;

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInv_Leaf_Image : public UInv_Leaf
{
	GENERATED_BODY()

public:
	void SetImage(UTexture2D* InTexture) const;
	void SetBoxSize(const FVector2D& InSize) const;
	void SetImageSize(const FVector2D& InSize) const;
	FVector2D GetImageSize() const;
	
private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<USizeBox> SizeBox_Icon;
};
