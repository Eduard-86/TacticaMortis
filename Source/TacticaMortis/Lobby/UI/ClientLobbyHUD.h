// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseLobbyHUD.h"

#include "ClientLobbyHUD.generated.h"


UCLASS()
class TACTICAMORTIS_API AClientLobbyHUD : public ABaseLobbyHUD
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void UpdateWidgetPlayerName(const FString& NewPlayerName);
	UFUNCTION(BlueprintCallable)
	void UpdateWidgetPlayerTeamIndex(int32 NewTeamIndex);
	UFUNCTION(BlueprintCallable)
	void UpdateWidgetPlayerReadyFlag(bool NewReadyFlag);
	UFUNCTION(BlueprintCallable)
	void UpdateWidgetPlayerSelectCharacter(FName NewCharacterId);

};
