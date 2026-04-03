// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LobbyHUD.generated.h"

/**
 * 
 */



UCLASS()
class TACTICAMORTIS_API ALobbyHUD : public AHUD
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable) 
	void CreateBaseWidget(bool isHost);

};
