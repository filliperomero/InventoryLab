// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Inv_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class INVENTORYSYSTEM_API AInv_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void PrimaryInteract();
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory System")
	TObjectPtr<UInputMappingContext> DefaultIMC;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory System")
	TObjectPtr<UInputAction> PrimaryInteractAction;
};
