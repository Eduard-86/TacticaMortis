// Fill out your copyright notice in the Description page of Project Settings.

#include "HostLobbyHUD.h"

#include "ClientLobbyHUD.h"
#include "Lobby/PlayerSettings/HostLobbyPlayerController.h"

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

void AHostLobbyHUD::UpdateWidgetPlayerAddCharacterByIndex(int32 ClientIndex, FName CharacterRowName)
{
	if (AHostLobbyPlayerController* LPC = Cast<AHostLobbyPlayerController>(GetOwningPlayerController()))
		LPC->UpdateAddCharacterByIndex(ClientIndex, CharacterRowName);
}

void AHostLobbyHUD::UpdateWidgetPlayerRemoveCharacterByIndex(int32 ClientIndex, FString CharacterInstanceId)
{
	if (AHostLobbyPlayerController* LPC = Cast<AHostLobbyPlayerController>(GetOwningPlayerController()))
		LPC->UpdateRemoveCharacterByIndex(ClientIndex, CharacterInstanceId);
}

void AHostLobbyHUD::UpdateWidgetHostAddCharacter(FName CharacterRowName)
{
	if (AHostLobbyPlayerController* LPC = Cast<AHostLobbyPlayerController>(GetOwningPlayerController()))
		LPC->UpdateHostAddCharacter(CharacterRowName);
}

void AHostLobbyHUD::UpdateWidgetHostRemoveCharacter(FString CharacterInstanceId)
{
	if (AHostLobbyPlayerController* LPC = Cast<AHostLobbyPlayerController>(GetOwningPlayerController()))
		LPC->UpdateHostRemoveCharacter(CharacterInstanceId);
}

void AHostLobbyHUD::UpdateWidgetHostChangeTeamIndexCharacter(FString CharacterInstanceId, int32 NewTeamIndex)
{
	if (AHostLobbyPlayerController* LPC = Cast<AHostLobbyPlayerController>(GetOwningPlayerController()))
		LPC->UpdateHostChangeCharacterTeamIndex(CharacterInstanceId, NewTeamIndex);
}
