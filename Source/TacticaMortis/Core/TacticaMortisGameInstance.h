// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TacticaMortisGameInstance.generated.h"

class ULobbyDataManager;
/**
 * 
 */
UCLASS()
class TACTICAMORTIS_API UTacticaMortisGameInstance : public UGameInstance
{
	GENERATED_BODY()


public: 

	void SavePlayersData(ULobbyDataManager* Data) { LobbyData = Data; };
	
	TObjectPtr<ULobbyDataManager> GetPlayersData() { return LobbyData; };

protected:

	TObjectPtr<ULobbyDataManager> LobbyData;
	
};
