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
	void UpdateWidgetPlayerSelectCharacterByIndex(int32 ClientIndex, FName NewCharacterId);

};
