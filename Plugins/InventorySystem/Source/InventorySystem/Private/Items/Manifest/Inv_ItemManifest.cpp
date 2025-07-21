// Copyright Fillipe Romero. All Rights Reserved.

#include "Items/Manifest/Inv_ItemManifest.h"

#include "Items/Inv_InventoryItem.h"
#include "Items/Components/Inv_ItemComponent.h"

UInv_InventoryItem* FInv_ItemManifest::Manifest(UObject* NewOuter)
{
	UInv_InventoryItem* Item = NewObject<UInv_InventoryItem>(NewOuter, UInv_InventoryItem::StaticClass());
	Item->SetItemManifest(*this);

	return Item;
}

void FInv_ItemManifest::SpawnPickupActor(const UObject* WorldContextObject, const FVector& SpawnLocation, const FRotator& SpawnRotation)
{
	checkf(PickupActorClass, TEXT("Pickup Actor Class is not set in: Inv_ItemManifest"));

	if (!IsValid(WorldContextObject)) return;

	AActor* SpawnedActor = WorldContextObject->GetWorld()->SpawnActor<AActor>(PickupActorClass, SpawnLocation, SpawnRotation);

	if (!IsValid(SpawnedActor)) return;

	UInv_ItemComponent* ItemComp = SpawnedActor->FindComponentByClass<UInv_ItemComponent>();
	checkf(ItemComp, TEXT("Spawned Actor should have Item Component on it."));

	ItemComp->InitItemManifest(*this);
}
