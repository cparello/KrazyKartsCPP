// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "KrazyKartsCPPGameMode.h"
#include "KrazyKartsCPPPawn.h"
#include "KrazyKartsCPPHud.h"

AKrazyKartsCPPGameMode::AKrazyKartsCPPGameMode()
{
	DefaultPawnClass = AKrazyKartsCPPPawn::StaticClass();
	HUDClass = AKrazyKartsCPPHud::StaticClass();
}
