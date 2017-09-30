// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameModeBase.h"
#include "PZ_4GameMode.generated.h"

DECLARE_DELEGATE(FMyDel);
DECLARE_DELEGATE_OneParam(FMyOneParamDel, bool);

UCLASS(minimalapi)
class APZ_4GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APZ_4GameMode();

	FTimerDynamicDelegate MBegOverlab;
	FMyOneParamDel ActorVisibility;
};



