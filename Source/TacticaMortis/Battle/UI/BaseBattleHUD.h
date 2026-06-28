// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BaseBattleHUD.generated.h"


UCLASS(Abstract)
class TACTICAMORTIS_API ABaseBattleHUD : public AHUD
{
	GENERATED_BODY()

public:

	UFUNCTION()
	virtual void BeginPlay() override;

};

