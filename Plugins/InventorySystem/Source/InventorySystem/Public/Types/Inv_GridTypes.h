﻿// Copyright Fillipe Romero. All Rights Reserved.

#pragma once

#include "Inv_GridTypes.generated.h"

UENUM(BlueprintType)
enum class EInv_ItemCategory : uint8
{
	None,
	Equippable,
	Consumable,
	Craftable
};