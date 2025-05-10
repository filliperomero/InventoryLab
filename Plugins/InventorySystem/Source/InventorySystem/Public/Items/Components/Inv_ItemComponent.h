// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inv_ItemComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORYSYSTEM_API UInv_ItemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInv_ItemComponent();

private:
	UPROPERTY(EditAnywhere, Category = "Inventory System")
	FString PickupMessage;

public:
	FString GetPickupMessage() const { return PickupMessage; }
};
