// Fill out your copyright notice in the Description page of Project Settings.

#include "HostLobbyHUD.h"

#include "ClientLobbyHUD.h"
#include "Lobby/CharacterSettings/HostLobbyPlayerController.h"

void AHostLobbyHUD::UpdateWidgetPlayerNameByIndex(int32 ClientIndex, const FString& NewPlayerName)
{
	if (AHostLobbyPlayerController* LPC = Cast<AHostLobbyPlayerController>(GetOwningPlayerController()))
		LPC->UpdateNameByIndex(ClientIndex, NewPlayerName);
}

void AHostLobbyHUD::UpdateWidgetPlayerTeamIndexByIndex(int32 ClientIndex, int32 NewTeamIndex)
{
	if (AHostLobbyPlayerController* LPC = Cast<AHostLobbyPlayerController>(GetOwningPlayerController()))
		LPC->UpdateTeamIndexByIndex(ClientIndex, NewTeamIndex);
}

void AHostLobbyHUD::UpdateWidgetPlayerReadyFlagByIndex(int32 ClientIndex, bool NewReadyFlag)
{
	if (AHostLobbyPlayerController* LPC = Cast<AHostLobbyPlayerController>(GetOwningPlayerController()))
		LPC->UpdateReadyFlagByIndex(ClientIndex, NewReadyFlag);
}

void AHostLobbyHUD::UpdateWidgetPlayerSelectCharacterByIndex(int32 ClientIndex, FName NewCharacterId)
{
	if (AHostLobbyPlayerController* LPC = Cast<AHostLobbyPlayerController>(GetOwningPlayerController()))
		LPC->UpdateSelectCharacterByIndex(ClientIndex, NewCharacterId);
}
