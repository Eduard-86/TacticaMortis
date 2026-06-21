// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseLobbyHUD.h"

#include "HostLobbyHUD.generated.h"


UCLASS()
class TACTICAMORTIS_API AHostLobbyHUD : public ABaseLobbyHUD
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void UpdateWidgetPlayerNameByIndex(int32 ClientIndex, const FString& NewPlayerName);
	UFUNCTION(BlueprintCallable)
	void UpdateWidgetPlayerTeamIndexByIndex(int32 ClientIndex, int32 NewTeamIndex);
	UFUNCTION(BlueprintCallable)
	void UpdateWidgetPlayerReadyFlagByIndex(int32 ClientIndex, bool NewReadyFlag);

	UFUNCTION(BlueprintCallable)
	void UpdateWidgetPlayerAddCharacterByIndex(int32 ClientIndex, FName CharacterRowName);
	UFUNCTION(BlueprintCallable)
	void UpdateWidgetPlayerRemoveCharacterByIndex(int32 ClientIndex, FString CharacterInstanceId);

	UFUNCTION(BlueprintCallable)
	void UpdateWidgetHostAddCharacter(FName CharacterRowName);
	UFUNCTION(BlueprintCallable)
	void UpdateWidgetHostRemoveCharacter(FString CharacterInstanceId);
	UFUNCTION(BlueprintCallable)
	void UpdateWidgetHostChangeTeamIndexCharacter(FString CharacterInstanceId, int32 NewTeamIndex);

};
