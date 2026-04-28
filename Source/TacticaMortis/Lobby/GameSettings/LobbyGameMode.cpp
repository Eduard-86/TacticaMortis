// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/GameSettings/LobbyGameMode.h"
#include "LobbyGameState.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	GetGameState<ALobbyGameState>()->AddNewPlayer(NewPlayer);

}
