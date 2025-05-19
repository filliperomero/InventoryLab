// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Inv_ItemFragment.generated.h"

USTRUCT(BlueprintType)
struct FInv_ItemFragment
{
	GENERATED_BODY()

	FInv_ItemFragment() {}
	// Rule of 5 (5 special member functions)
	// Copy Operations
	FInv_ItemFragment(const FInv_ItemFragment&) = default;
	FInv_ItemFragment& operator=(const FInv_ItemFragment&) = default;
	// Move Operations
	FInv_ItemFragment(FInv_ItemFragment&&) = default;
	FInv_ItemFragment& operator=(FInv_ItemFragment&&) = default;
	// virtual destructor
	virtual ~FInv_ItemFragment() {}

	FGameplayTag GetFragmentTag() const { return FragmentTag; }
	void SetFragmentTag(FGameplayTag Tag) { FragmentTag = Tag; }

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System", meta=(Categories="FragmentTags"))
	FGameplayTag FragmentTag = FGameplayTag::EmptyTag;
};

USTRUCT(BlueprintType)
struct FInv_GridFragment : public FInv_ItemFragment
{
	GENERATED_BODY()

	FIntPoint GetGridSize() const { return GridSize; }
	void SetGridSize(FIntPoint Size) { GridSize = Size; }

	float GetGridPadding() const { return GridPadding; }
	void SetGridPadding(float Padding) { GridPadding = Padding; }

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System")
	FIntPoint GridSize {1, 1 };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	float GridPadding { 0.f };
};

USTRUCT(BlueprintType)
struct FInv_ImageFragment : public FInv_ItemFragment
{
	GENERATED_BODY()

	UTexture2D* GetIcon() const { return Icon; }

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System")
	TObjectPtr<UTexture2D> Icon { nullptr };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	FVector2D IconDimensions { 44.f, 44.f };
};

USTRUCT(BlueprintType)
struct FInv_StackableFragment : public FInv_ItemFragment
{
	GENERATED_BODY()

	int32 GetStackCount() const { return StackCount; }
	int32 GetMaxStackSize() const { return MaxStackSize; }

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System")
	int32 MaxStackSize { 1 };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	int32 StackCount { 1 };
};
