// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_CharacterDisplay.generated.h"

UCLASS()
class INVENTORYSYSTEM_API UInv_CharacterDisplay : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	FVector2D CurrentPosition;
	FVector2D LastPosition;
	bool bIsDragging { false };
	TWeakObjectPtr<USkeletalMeshComponent> Mesh;
};
