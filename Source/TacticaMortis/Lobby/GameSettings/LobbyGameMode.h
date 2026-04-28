// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
class ALobbyHUD;

UCLASS()
class TACTICAMORTIS_API ALobbyGameMode : public AGameMode
{
	GENERATED_BODY()
	
public: 

	UPROPERTY(Blueprintable, EditAnywhere)
	TSubclassOf<ALobbyHUD> HostBaseHUD;

	UPROPERTY(Blueprintable, EditAnywhere)
	TSubclassOf<ALobbyHUD> ClientBaseHUD;

public:

	virtual void PostLogin(APlayerController* NewPlayer) override;
};
