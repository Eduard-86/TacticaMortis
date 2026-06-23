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
	//, meta = (RowType = "/Script/TacticaMortis.MapInfo")
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "LobbySetting")
	TObjectPtr<UDataTable> MapDataTable;

	UPROPERTY(EditDefaultsOnly, Category = "LobbySetting")
	TSubclassOf<AHostLobbyHUD> HostHUD;

	UPROPERTY(EditDefaultsOnly, Category = "LobbySetting")
	TSubclassOf<AClientLobbyHUD> ClientHUD;


	UPROPERTY(EditDefaultsOnly, Category = "LobbySetting")
	TSubclassOf<AController> ClientPlayerControllerClass;

	UPROPERTY(EditDefaultsOnly, Category = "LobbySetting")
	TSubclassOf<AController> HostPlayerControllerClass;

public:

	virtual APlayerController* SpawnPlayerController(ENetRole InRemoteRole, const FString& Options) override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

	UFUNCTION(BlueprintCallable)
	void StartBattle(FName SelectedMapRowName);
};
