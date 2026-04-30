// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/GameSettings/LobbyGameState.h"
#include "GameFramework/PlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Net/Core/PushModel/PushModel.h"


ALobbyGameState::ALobbyGameState()
{
	bReplicates = true;
}

void ALobbyGameState::AddNewPlayer(const APlayerController* PlayerController)
{
	if (!HasAuthority()) return;
	if (!PlayerController || !PlayerController->PlayerState) return;

	//PlayerLobbyInfos.AddDefaulted();

	//PlayerLobbyInfos.Last().PlayerUniqueId = PlayerController->PlayerState->GetUniqueId().ToString();

	PlayerLobbyInfos.Emplace(PlayerController->PlayerState->GetUniqueId().ToString());

	PlayerLobbyInfos.Last().PlayerName = PlayerController->PlayerState->GetPlayerName();

	MARK_PROPERTY_DIRTY_FROM_NAME(ALobbyGameState, PlayerLobbyInfos, this);
}

void ALobbyGameState::UpdatePlayerName(const APlayerController* PC, FString PlayerName)
{
	if (!HasAuthority()) return;
	if (!PC || !PC->PlayerState) return;

	FString TargetId = PC->PlayerState->GetUniqueId().ToString();

	FPlayerLobbyInfo* PlayerLobbyInfo = PlayerLobbyInfos.FindByPredicate(
		[&TargetId](const FPlayerLobbyInfo& Info)->bool
			{return Info.PlayerUniqueId == TargetId; }
	);

	PlayerLobbyInfo->PlayerName = PlayerName;

	MARK_PROPERTY_DIRTY_FROM_NAME(ALobbyGameState, PlayerLobbyInfos, this);
}

void ALobbyGameState::UpdatePlayerTeamIndex(const APlayerController* PC, int32 TeamIndex)
{
	if (!HasAuthority()) return;
	if (!PC || !PC->PlayerState) return;
}

void ALobbyGameState::UpdatePlayerReadyFlag(const APlayerController* PC, bool ReadyFlag)
{
	if (!HasAuthority()) return;
	if (!PC || !PC->PlayerState) return;
}

void ALobbyGameState::UpdatePlayerSelectCharacter(const APlayerController* PC, FName CharacterId)
{
	if (!HasAuthority()) return;
	if (!PC || !PC->PlayerState) return;
}

void ALobbyGameState::UpdateHostAddCharacterFromPlayer(const APlayerController* PC, FName CharacterId)
{
	if (!HasAuthority()) return;
	if (!PC || !PC->PlayerState) return;
}

void ALobbyGameState::UpdateHostRemoveCharacterFromPlayer(const APlayerController* PC, FName CharacterId)
{
	if (!HasAuthority()) return;
	if (!PC || !PC->PlayerState) return;
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
