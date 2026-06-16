// Fill out your copyright notice in the Description page of Project Settings.


#include "HostLobbyPlayerController.h"

#include "GameFramework/PlayerState.h"
#include "Lobby/GameSettings/LobbyGameState.h"

ALobbyGameState* AHostLobbyPlayerController::CheckSafeLobbyGameState()
{
	if (LobbyGameState == nullptr)
	{
		LobbyGameState = Cast<ALobbyGameState>(
			GetWorld()->GetGameState());
	}
	
	return LobbyGameState;
}

APlayerController* AHostLobbyPlayerController::FindClientPCbyIndex(int ClientIndex)
{
	if (!LobbyGameState) return nullptr;
	if (!LobbyGameState->PlayerLobbyInfos.IsValidIndex(ClientIndex))
	{
		UE_LOG(LogTemp, Warning, TEXT("FindClientPCbyIndex: Invalid index %d"), ClientIndex);
		return nullptr;
	}

	FString TargetPlayerID = LobbyGameState->PlayerLobbyInfos[ClientIndex].PlayerUniqueId;

	for (TObjectPtr<APlayerState> TargetPlayerState : LobbyGameState->PlayerArray)
	{
		if (TargetPlayerState->GetUniqueId().ToString() == TargetPlayerID)
		{
			return TargetPlayerState->GetPlayerController();
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("FindClientPCbyIndex: PlayerController not found for ID %s"), *TargetPlayerID);
	return nullptr;
}

AHostLobbyPlayerController::AHostLobbyPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void AHostLobbyPlayerController::UpdateNameByIndex(int PlayerIndex, const FString& PlayerName)
{
	if (!HasAuthority()) return;
	if (!CheckSafeLobbyGameState()) return;

	APlayerController* TargetPC = FindClientPCbyIndex(PlayerIndex);

	if (TargetPC != nullptr)
		LobbyGameState->UpdatePlayerName(TargetPC, PlayerName);
}

void AHostLobbyPlayerController::UpdateTeamIndexByIndex(int PlayerIndex, int32 TeamIndex)
{
	if (!HasAuthority()) return;
	if (!CheckSafeLobbyGameState()) return;

	APlayerController* TargetPC = FindClientPCbyIndex(PlayerIndex);

	if (TargetPC != nullptr)
		LobbyGameState->UpdatePlayerTeamIndex(TargetPC, TeamIndex);
}

void AHostLobbyPlayerController::UpdateReadyFlagByIndex(int PlayerIndex, bool ReadyFlag)
{
	if (!HasAuthority()) return;
	if (!CheckSafeLobbyGameState()) return;
	
	APlayerController* TargetPC = FindClientPCbyIndex(PlayerIndex);

	if (TargetPC != nullptr)
		LobbyGameState->UpdatePlayerReadyFlag(TargetPC, ReadyFlag);
}



void AHostLobbyPlayerController::UpdateAddCharacterByIndex(int PlayerIndex, FName CharacterId)
{
	if (!HasAuthority()) return;
	if (!CheckSafeLobbyGameState()) return;

	APlayerController* TargetPC = FindClientPCbyIndex(PlayerIndex);

	if (TargetPC != nullptr)
		LobbyGameState->UpdateHostAddCharacterFromPlayer(TargetPC, CharacterId);
}

void AHostLobbyPlayerController::UpdateRemoveCharacterByIndex(int PlayerIndex, FName CharacterRowName)
{
	if (!HasAuthority()) return;
	if (!CheckSafeLobbyGameState()) return;

	APlayerController* TargetPC = FindClientPCbyIndex(PlayerIndex);

	if (TargetPC != nullptr)
		LobbyGameState->UpdateHostRemoveCharacterFromPlayer(TargetPC, CharacterRowName);
}


void AHostLobbyPlayerController::UpdateHostAddCharacter(FName CharacterRowName)
{
	if (!HasAuthority()) return;
	if (!CheckSafeLobbyGameState()) return;

	LobbyGameState->UpdateAddCharacterFromHost(CharacterRowName);
}

void AHostLobbyPlayerController::UpdateHostRemoveCharacter(FName CharacterRowName)
{
	if (!HasAuthority()) return;
	if (!CheckSafeLobbyGameState()) return;

	LobbyGameState->UpdateRemoveCharacterFromHost(CharacterRowName);
}

void AHostLobbyPlayerController::UpdateHostChangeCharacterTeamIndex(FName CharacterRowName, int32 NewTeamIndex)
{
	if (!HasAuthority()) return;
	if (!CheckSafeLobbyGameState()) return;

	LobbyGameState->UpdateChangeCharacterTeamIndexFromHost(CharacterRowName, NewTeamIndex);
}
