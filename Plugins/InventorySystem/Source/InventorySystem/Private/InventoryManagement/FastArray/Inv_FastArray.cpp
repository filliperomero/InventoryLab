// Copyright Fillipe Romero. All Rights Reserved.

#include "InventoryManagement/FastArray/Inv_FastArray.h"

#include "InventoryManagement/Components/Inv_InventoryComponent.h"
#include "Items/Inv_InventoryItem.h"
#include "Items/Components/Inv_ItemComponent.h"

TArray<UInv_InventoryItem*> FInv_InventoryFastArray::GetAllItems() const
{
	TArray<UInv_InventoryItem*> Results;
	Results.Reserve(Entries.Num());

	for (const auto& Entry : Entries)
	{
		if (!IsValid(Entry.Item)) continue;

		Results.Add(Entry.Item);
	}

	return Results;
}

void FInv_InventoryFastArray::PreReplicatedRemove(const TArrayView<int32> RemovedIndices, int32 FinalSize)
{
	UInv_InventoryComponent* InventoryComp= Cast<UInv_InventoryComponent>(OwnerComponent);

	if (!IsValid(InventoryComp)) return;

	for (const int32 Index : RemovedIndices)
	{
		InventoryComp->OnItemRemoved.Broadcast(Entries[Index].Item);
	}
}

void FInv_InventoryFastArray::PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize)
{
	UInv_InventoryComponent* InventoryComp= Cast<UInv_InventoryComponent>(OwnerComponent);

	if (!IsValid(InventoryComp)) return;
	
	for (const int32 Index : AddedIndices)
	{
		InventoryComp->OnItemAdded.Broadcast(Entries[Index].Item);
	}
}

UInv_InventoryItem* FInv_InventoryFastArray::AddEntry(UInv_ItemComponent* ItemComponent)
{
	check(OwnerComponent)
	
	AActor* OwningActor = OwnerComponent->GetOwner();
	check(OwningActor->HasAuthority())

	UInv_InventoryComponent* InventoryComp = Cast<UInv_InventoryComponent>(OwnerComponent);

	if (!IsValid(InventoryComp)) return nullptr;
	
	FInv_InventoryEntry& NewEntry = Entries.AddDefaulted_GetRef();
	NewEntry.Item = ItemComponent->GetItemManifest().Manifest(OwningActor);

	InventoryComp->AddRepSubObj(NewEntry.Item);

	// This will tell that it needs to be replicated
	MarkItemDirty(NewEntry);

	return NewEntry.Item;
}

UInv_InventoryItem* FInv_InventoryFastArray::AddEntry(UInv_InventoryItem* InventoryItem)
{
	// We only want to add on the Server
	check(OwnerComponent)
	
	AActor* OwningActor = OwnerComponent->GetOwner();
	check(OwningActor->HasAuthority())

	FInv_InventoryEntry& NewEntry = Entries.AddDefaulted_GetRef();
	NewEntry.Item = InventoryItem;

	// This will tell that it needs to be replicated
	MarkItemDirty(NewEntry);

	return InventoryItem;
}

void FInv_InventoryFastArray::RemoveEntry(UInv_InventoryItem* InventoryItem)
{
	for (auto EntryIt = Entries.CreateIterator(); EntryIt; ++EntryIt)
	{
		FInv_InventoryEntry& Entry = *EntryIt;
		if (Entry.Item == InventoryItem)
		{
			EntryIt.RemoveCurrent();

			// This will tell that it needs to be replicated
			MarkArrayDirty();
		}
	}
}
