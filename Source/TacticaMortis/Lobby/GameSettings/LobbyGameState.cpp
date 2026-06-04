// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/GameSettings/LobbyGameState.h"
#include "GameFramework/PlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Net/Core/PushModel/PushModel.h"

ALobbyGameState::ALobbyGameState()
{
	bReplicates = true;
}

int32 ALobbyGameState::FindPlayerInfoIndex(const APlayerController* PC)
{
	if (!PC) return -1;
	if (!PC->PlayerState) return -1;

	for (int i = 0; i <= PlayerLobbyInfos.Num(); i++)
	{
		if (PlayerLobbyInfos[i].PlayerUniqueId == PC->PlayerState->GetUniqueId().ToString())
		{
			return i;
		}
	}
	return -1;
}

FPlayerLobbyInfo* ALobbyGameState::FindPlayerInfo(const APlayerController* PC)
{
	if (!PC || !PC->PlayerState) return nullptr;

	FString TargetId = PC->PlayerState->GetUniqueId().ToString();

	return PlayerLobbyInfos.FindByPredicate(
		[&TargetId](const FPlayerLobbyInfo& Info)->bool
		{
			return Info.PlayerUniqueId == TargetId;
		}
	);
}

void ALobbyGameState::NotifyDataChanged()
{
	OnPlayerInfoChanged.Broadcast();

	MARK_PROPERTY_DIRTY_FROM_NAME(ALobbyGameState, PlayerLobbyInfos, this);
}

void ALobbyGameState::AddNewPlayer(const APlayerController* PlayerController)
{
	if (!HasAuthority()) return;
	if (!PlayerController || !PlayerController->PlayerState) return;

	//PlayerLobbyInfos.AddDefaulted();

	//PlayerLobbyInfos.Last().PlayerUniqueId = PlayerController->PlayerState->GetUniqueId().ToString();

	PlayerLobbyInfos.Emplace(PlayerController->PlayerState->GetUniqueId().ToString());

	PlayerLobbyInfos.Last().PlayerName = PlayerController->PlayerState->GetPlayerName();

	NotifyDataChanged();
}

void ALobbyGameState::UpdatePlayerName(const APlayerController* PC, FString PlayerName)
{
	if (!HasAuthority()) return;

	if (FPlayerLobbyInfo* Info = FindPlayerInfo(PC))
	{
		Info->PlayerName = PlayerName;
		NotifyDataChanged();
	}
}

void ALobbyGameState::UpdatePlayerTeamIndex(const APlayerController* PC, int32 TeamIndex)
{
	if (!HasAuthority()) return;

	if (FPlayerLobbyInfo* Info = FindPlayerInfo(PC))
	{
		Info->TeamIndex = TeamIndex;
		NotifyDataChanged();
	}
}

void ALobbyGameState::UpdatePlayerReadyFlag(const APlayerController* PC, bool ReadyFlag)
{
	if (!HasAuthority()) return;

	if (FPlayerLobbyInfo* Info = FindPlayerInfo(PC))
	{
		Info->bIsReady = ReadyFlag;
		NotifyDataChanged();
	}
}

void ALobbyGameState::UpdatePlayerSelectCharacter(const APlayerController* PC, FName CharacterId)
{
	if (!HasAuthority()) return;

	if (FPlayerLobbyInfo* Info = FindPlayerInfo(PC))
	{
		Info->PlayerCharacterId = CharacterId;
		NotifyDataChanged();
	}
}

void ALobbyGameState::UpdateHostAddCharacterFromPlayer(const APlayerController* PC, FName CharacterId)
{
	if (!HasAuthority()) return;

	if (FPlayerLobbyInfo* Info = FindPlayerInfo(PC))
	{
		Info->AssignedCharacterIdsFromHost.Add(CharacterId);
		NotifyDataChanged();
	}
}

void ALobbyGameState::UpdateHostRemoveCharacterFromPlayer(const APlayerController* PC, FName CharacterId)
{
	if (!HasAuthority()) return;

	if (FPlayerLobbyInfo* Info = FindPlayerInfo(PC))
	{
		Info->AssignedCharacterIdsFromHost.Remove(CharacterId);
		NotifyDataChanged();
	}
}


void ALobbyGameState::OnRep_PlayerLobbyInfos()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep triggered! Count: %d"), PlayerLobbyInfos.Num());

	OnPlayerInfoChanged.Broadcast();
}

void ALobbyGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ALobbyGameState, PlayerLobbyInfos, COND_None, REPNOTIFY_Always);
}
