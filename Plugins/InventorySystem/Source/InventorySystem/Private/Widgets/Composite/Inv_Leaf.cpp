// Copyright Fillipe Romero. All Rights Reserved.

#include "Widgets/Composite/Inv_Leaf.h"

void UInv_Leaf::ApplyFunction(FuncType Function)
{
	Function(this);
}
