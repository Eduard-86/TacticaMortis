// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "LobbyGameState.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnPlayerListChanged);

USTRUCT(BlueprintType)
struct FPlayerLobbyInfo  
{
    GENERATED_BODY()

    FPlayerLobbyInfo(FString UniqueId) :
        PlayerUniqueId(UniqueId){}

    FPlayerLobbyInfo()
    {}

    // Мб убери потом BlueprintReadWrite, но мб для UI нужно будет оставить 

    UPROPERTY(BlueprintReadWrite)
    FString PlayerUniqueId = "NONE";

    UPROPERTY(BlueprintReadWrite)
    FString PlayerName = "NewClient";

    UPROPERTY(BlueprintReadWrite)
    int32 TeamIndex = -1;           

    UPROPERTY(BlueprintReadWrite)
    bool bIsReady = false;          

    UPROPERTY(BlueprintReadWrite)
    FName PlayerCharacterId;

    UPROPERTY(BlueprintReadWrite)
    TArray<FName> AssignedCharacterIdsFromHost;  

private:
};

UCLASS()
class TACTICAMORTIS_API ALobbyGameState : public AGameState
{
	GENERATED_BODY()

public:

    ALobbyGameState();

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_PlayerLobbyInfos)
    TArray<FPlayerLobbyInfo> PlayerLobbyInfos;

public:

    void AddNewPlayer(const APlayerController* PC);
    
	void UpdatePlayerName(const APlayerController* PC, FString PlayerName);
    void UpdatePlayerTeamIndex(const APlayerController* PC, int32 TeamIndex);
    void UpdatePlayerReadyFlag(const APlayerController* PC, bool ReadyFlag);
    void UpdatePlayerSelectCharacter(const APlayerController* PC, FName CharacterId);
    
	void UpdateHostAddCharacterFromPlayer(const APlayerController* PC, FName CharacterId);
    void UpdateHostRemoveCharacterFromPlayer(const APlayerController* PC, FName CharacterId);

public:

    FOnPlayerListChanged OnPlayerInfoChanged;

protected:

    UFUNCTION()
    void OnRep_PlayerLobbyInfos();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
