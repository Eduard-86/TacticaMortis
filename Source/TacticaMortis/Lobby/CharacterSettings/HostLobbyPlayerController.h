// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HostLobbyPlayerController.generated.h"

class ALobbyGameState;

UCLASS()
class TACTICAMORTIS_API AHostLobbyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	ALobbyGameState* CheckSafeLobbyGameState();

	APlayerController* FindClientPCbyIndex(int ClientIndex);

	AHostLobbyPlayerController();

public: 

	UFUNCTION(BlueprintCallable)
	void UpdateNameByIndex(int PlayerIndex, const FString& PlayerName);
	UFUNCTION(BlueprintCallable)
	void UpdateTeamIndexByIndex(int PlayerIndex, int32 TeamIndex);
	UFUNCTION(BlueprintCallable)
	void UpdateReadyFlagByIndex(int PlayerIndex, bool ReadyFlag);

	UFUNCTION(BlueprintCallable)
	void UpdateAddCharacterByIndex(int PlayerIndex, FName CharacterRowName);
	UFUNCTION(BlueprintCallable)
	void UpdateRemoveCharacterByIndex(int PlayerIndex, FName CharacterRowName);

	UFUNCTION(BlueprintCallable)
	void UpdateHostAddCharacter(FName CharacterRowName);
	UFUNCTION(BlueprintCallable)
	void UpdateHostRemoveCharacter(FName CharacterRowName);
	UFUNCTION(BlueprintCallable)
	void UpdateHostChangeCharacterTeamIndex(FName CharacterRowName, int32 NewTeamIndex);


	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ALobbyGameState> LobbyGameState;
};
