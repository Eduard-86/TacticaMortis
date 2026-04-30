// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
class AClientLobbyHUD;
class AHostLobbyHUD;
;

UCLASS()
class TACTICAMORTIS_API ALobbyGameMode : public AGameMode
{
	GENERATED_BODY()
	
public: 

	UPROPERTY(Blueprintable, EditAnywhere)
	TSubclassOf<AHostLobbyHUD> HostBaseHUD;

	UPROPERTY(Blueprintable, EditAnywhere)
	TSubclassOf<AClientLobbyHUD> ClientBaseHUD;

public:

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;
};
