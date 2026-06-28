// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPlayerController.generated.h"

class ALobbyGameState;

UCLASS()
class TACTICAMORTIS_API ALobbyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	ALobbyGameState* CheckSafeLobbyGameState();

	ALobbyPlayerController();

public: 

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_UpdateName(const FString& PlayerName);
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_UpdateTeamIndex(int32 TeamIndex);
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_UpdateReadyFlag(bool ReadyFlag);
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_UpdateSelectCharacter(FName CharacterRowName);
	

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ALobbyGameState> LobbyGameState;
};
