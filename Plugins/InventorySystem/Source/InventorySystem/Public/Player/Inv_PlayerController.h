// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Inv_PlayerController.generated.h"

class UInv_InventoryComponent;
class UInv_HUDWidget;
class UInputMappingContext;
class UInputAction;

UCLASS()
class INVENTORYSYSTEM_API AInv_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AInv_PlayerController();
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Inventory System")
	void ToggleInventory();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void PrimaryInteract();
	void CreateHUDWidget();
	void TraceForItem();

	TWeakObjectPtr<UInv_InventoryComponent> InventoryComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory System")
	TObjectPtr<UInputMappingContext> DefaultIMC;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory System")
	TObjectPtr<UInputAction> PrimaryInteractAction;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory System")
	TObjectPtr<UInputAction> ToggleInventoryAction;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory System")
	TSubclassOf<UInv_HUDWidget> HUDWidgetClass;

	UPROPERTY()
	TObjectPtr<UInv_HUDWidget> HUDWidget;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory System")
	double TraceLength;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory System")
	TEnumAsByte<ECollisionChannel> ItemTraceChannel;

	// This will not affect Garbage collector since UPRORPERTY prevents the GC
	TWeakObjectPtr<AActor> CurrentHitActor;
	TWeakObjectPtr<AActor> LastHitActor;
};
