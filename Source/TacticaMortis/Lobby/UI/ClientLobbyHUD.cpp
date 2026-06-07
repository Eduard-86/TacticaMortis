// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientLobbyHUD.h"

#include "Lobby/CharacterSettings/LobbyPlayerController.h"


void AClientLobbyHUD::UpdateWidgetPlayerName(const FString& NewPlayerName)
{
	if (ALobbyPlayerController* LPC = Cast<ALobbyPlayerController>(GetOwningPlayerController()))
		LPC->Server_UpdateName(NewPlayerName);
}

void AClientLobbyHUD::UpdateWidgetPlayerTeamIndex(int32 NewTeamIndex)
{
	if (ALobbyPlayerController* LPC = Cast<ALobbyPlayerController>(GetOwningPlayerController()))
		LPC->Server_UpdateTeamIndex(NewTeamIndex);
}

void AClientLobbyHUD::UpdateWidgetPlayerReadyFlag(bool NewReadyFlag)
{
	if (ALobbyPlayerController* LPC = Cast<ALobbyPlayerController>(GetOwningPlayerController()))
		LPC->Server_UpdateReadyFlag(NewReadyFlag);
}

void AClientLobbyHUD::UpdateWidgetPlayerSelectCharacter(FName NewCharacterId)
{
	if (ALobbyPlayerController* LPC = Cast<ALobbyPlayerController>(GetOwningPlayerController()))
		LPC->Server_UpdateSelectCharacter(NewCharacterId);
}
