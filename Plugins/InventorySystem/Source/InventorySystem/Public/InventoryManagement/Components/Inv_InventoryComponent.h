// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inv_InventoryComponent.generated.h"

class UInv_InventoryBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORYSYSTEM_API UInv_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInv_InventoryComponent();

	void ToggleInventoryMenu();

protected:
	virtual void BeginPlay() override;

private:
	void ConstructInventory();

	TWeakObjectPtr<APlayerController> OwningController;

	UPROPERTY()
	TObjectPtr<UInv_InventoryBase> InventoryMenu;

	UPROPERTY(EditAnywhere, Category = "Inventory System")
	TSubclassOf<UInv_InventoryBase> InventoryMenuClass;

	bool bIsInventoryMenuOpen = false;
	void OpenInventoryMenu();
	void CloseInventoryMenu();
};
