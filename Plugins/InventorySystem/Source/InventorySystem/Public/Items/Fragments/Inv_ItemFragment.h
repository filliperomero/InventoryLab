// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StructUtils/InstancedStruct.h"
#include "Inv_ItemFragment.generated.h"

class AInv_EquipActor;
class UInv_CompositeBase;
class APlayerController;

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
	virtual void Manifest() {}

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System", meta=(Categories="FragmentTags"))
	FGameplayTag FragmentTag = FGameplayTag::EmptyTag;
};

/** Item Fragment specifically for assimilation into a widget. */
USTRUCT(BlueprintType)
struct FInv_InventoryItemFragment : public FInv_ItemFragment
{
	GENERATED_BODY()

	virtual void Assimilate(UInv_CompositeBase* Composite) const;

protected:
	bool MatchesWidgetTag(const UInv_CompositeBase* Composite) const;
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
struct FInv_ImageFragment : public FInv_InventoryItemFragment
{
	GENERATED_BODY()

	UTexture2D* GetIcon() const { return Icon; }
	virtual void Assimilate(UInv_CompositeBase* Composite) const override;

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System")
	TObjectPtr<UTexture2D> Icon { nullptr };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	FVector2D IconDimensions { 44.f, 44.f };
};

USTRUCT(BlueprintType)
struct FInv_TextFragment : public FInv_InventoryItemFragment
{
	GENERATED_BODY()

	FText GetText() const { return FragmentText; }
	void SetText(const FText& InText) { FragmentText = InText; }
	virtual void Assimilate(UInv_CompositeBase* Composite) const override;

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System")
	FText FragmentText;
};

USTRUCT(BlueprintType)
struct FInv_LabeledNumberFragment : public FInv_InventoryItemFragment
{
	GENERATED_BODY()

	virtual void Manifest() override;

	FText GetText() const { return Text_Label; }
	void SetText(const FText& InText) { Text_Label = InText; }
	float GetValue() const { return Value; }
	virtual void Assimilate(UInv_CompositeBase* Composite) const override;

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System")
	FText Text_Label;

	UPROPERTY(VisibleAnywhere, Category = "Inventory System")
	float Value { 0.f };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	float MinValue { 0.f };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	float MaxValue { 0.f };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	int32 MinFractionalDigits { 1 };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	int32 MaxFractionalDigits { 1 };

	// When Manifesting for the first time, this fragment will randomize. However, once equipped and dropped, an item should retain the same value, so randomization should not occur.
	bool bRandomizeOnManifest { true };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	bool bCollapseLabel { false };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	bool bCollapseValue { false };
};

USTRUCT(BlueprintType)
struct FInv_StackableFragment : public FInv_ItemFragment
{
	GENERATED_BODY()

	int32 GetStackCount() const { return StackCount; }
	void SetStackCount(int32 Count) { StackCount = Count; }
	int32 GetMaxStackSize() const { return MaxStackSize; }

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System")
	int32 MaxStackSize { 1 };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	int32 StackCount { 1 };
};

/** Consume Fragments */

USTRUCT(BlueprintType)
struct FInv_ConsumeModifier : public FInv_LabeledNumberFragment
{
	GENERATED_BODY()

	virtual void OnConsume(APlayerController* PlayerController) {}
};

USTRUCT(BlueprintType)
struct FInv_ConsumableFragment : public FInv_InventoryItemFragment
{
	GENERATED_BODY()

	virtual void Assimilate(UInv_CompositeBase* Composite) const override;
	virtual void OnConsume(APlayerController* PlayerController);
	virtual void Manifest() override;

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System", meta = (ExcludeBaseStruct))
	TArray<TInstancedStruct<FInv_ConsumeModifier>> ConsumeModifiers;
};

USTRUCT(BlueprintType)
struct FInv_HealthPotionFragment : public FInv_ConsumeModifier
{
	GENERATED_BODY()

	virtual void OnConsume(APlayerController* PlayerController) override;
};

USTRUCT(BlueprintType)
struct FInv_ManaPotionFragment : public FInv_ConsumeModifier
{
	GENERATED_BODY()

	virtual void OnConsume(APlayerController* PlayerController) override;
};

/** Equipment Fragments */

USTRUCT(BlueprintType)
struct FInv_EquipModifier : public FInv_LabeledNumberFragment
{
	GENERATED_BODY()

	virtual void OnEquip(APlayerController* PC) {}
	virtual void OnUnequip(APlayerController* PC) {}
};

USTRUCT(BlueprintType)
struct FInv_StrengthModifier : public FInv_EquipModifier
{
	GENERATED_BODY()

	virtual void OnEquip(APlayerController* PC) override;
	virtual void OnUnequip(APlayerController* PC) override;
};

USTRUCT(BlueprintType)
struct FInv_EquipmentFragment : public FInv_InventoryItemFragment
{
	GENERATED_BODY()

	bool bEquipped { false };
	void OnEquip(APlayerController* PC);
	void OnUnequip(APlayerController* PC);
	virtual void Assimilate(UInv_CompositeBase* Composite) const override;
	virtual void Manifest() override;

	AInv_EquipActor* SpawnAttachedActor(USkeletalMeshComponent* AttachMesh) const;
	void DestroyAttachedActor();
	FGameplayTag GetEquipmentTag() const { return EquipmentType; }
	void SetEquippedActor(AInv_EquipActor* InEquipActor);

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System")
	TArray<TInstancedStruct<FInv_EquipModifier>> EquipModifiers;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	TSubclassOf<AInv_EquipActor> EquipActorClass = nullptr;

	TWeakObjectPtr<AInv_EquipActor> EquippedActor = nullptr;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	FName SocketAttachPoint { NAME_None };

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	FGameplayTag EquipmentType = FGameplayTag::EmptyTag;
};
