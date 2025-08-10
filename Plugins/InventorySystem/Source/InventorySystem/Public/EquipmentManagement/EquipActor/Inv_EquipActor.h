// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "Inv_EquipActor.generated.h"

UCLASS()
class INVENTORYSYSTEM_API AInv_EquipActor : public AActor
{
	GENERATED_BODY()

public:
	AInv_EquipActor();

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System", meta = (Categories="GameItems.Equipment"))
	FGameplayTag EquipmentType;

public:
	FGameplayTag GetEquipmentType() const { return EquipmentType; }
	void SetEquipmentType(const FGameplayTag& InEquipmentType) { EquipmentType = InEquipmentType; }
};
