// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/CharacterSettings/LobbyPlayerController.h"

#include "Lobby/GameSettings/LobbyGameState.h"

ALobbyGameState* ALobbyPlayerController::CheckSafeLobbyGameState()
{
	if (LobbyGameState == nullptr)
	{
		LobbyGameState = Cast<ALobbyGameState>(
			GetWorld()->GetGameState());
	}
	
	return LobbyGameState;
}

void ALobbyPlayerController::Server_UpdateName_Implementation(const FString& PlayerName)
{
	if (!HasAuthority()) return;
	if (!CheckSafeLobbyGameState()) return;

	LobbyGameState->UpdatePlayerName(this, PlayerName);
}

void ALobbyPlayerController::Server_UpdateTeamIndex_Implementation(int32 TeamIndex)
{
	if (!HasAuthority()) return;
	if (!CheckSafeLobbyGameState()) return;

	LobbyGameState->UpdatePlayerTeamIndex(this, TeamIndex);
}

void ALobbyPlayerController::Server_UpdateReadyFlag_Implementation(bool ReadyFlag)
{
	if (!HasAuthority()) return;
	if (!CheckSafeLobbyGameState()) return;

	LobbyGameState->UpdatePlayerReadyFlag(this, ReadyFlag);
}

void ALobbyPlayerController::Server_UpdateSelectCharacter_Implementation(FName CharacterId)
{
	if (!HasAuthority()) return;
	if (!CheckSafeLobbyGameState()) return;

	LobbyGameState->UpdatePlayerSelectCharacter(this, CharacterId);
}
