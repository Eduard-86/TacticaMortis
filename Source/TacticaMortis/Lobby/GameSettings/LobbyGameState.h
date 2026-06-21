// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "LobbyGameState.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnPlayerListChanged);

USTRUCT(BlueprintType)
struct FCharLobbyInfo
{
    GENERATED_BODY()

    FCharLobbyInfo(FString CharRowName = "NONE", int32 CharTeamIndex = -1)
        : RowName(CharRowName),
        InstanceId(FGuid::NewGuid().ToString()),
        TeamIndex(CharTeamIndex) {
    }


    UPROPERTY(BlueprintReadOnly)
    FString InstanceId;

    UPROPERTY(BlueprintReadWrite)
    FName RowName = "NONE";

	UPROPERTY(BlueprintReadWrite)
	int32 TeamIndex = -1;

    bool operator==(const FCharLobbyInfo& Other) const
    {
        return InstanceId == Other.InstanceId;
    }

};

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
    FName PlayerCharacterRowName;

    UPROPERTY(BlueprintReadWrite)
    TArray<FCharLobbyInfo> AssignedCharacterRowNamesFromHost;

private:
};

UCLASS()
class TACTICAMORTIS_API ALobbyGameState : public AGameState
{
	GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 FindPlayerInfoIndex(const APlayerController* PC);


protected:

    FPlayerLobbyInfo* FindPlayerInfo(const APlayerController* PC);
    
	void NotifyDataChanged();


public:

    ALobbyGameState();

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_PlayerLobbyInfos)
    TArray<FPlayerLobbyInfo> PlayerLobbyInfos;

public:

    void AddNewPlayer(const APlayerController* PC);
    
	void UpdatePlayerName(const APlayerController* PC, FString PlayerName);
    void UpdatePlayerTeamIndex(const APlayerController* PC, int32 TeamIndex);
    void UpdatePlayerReadyFlag(const APlayerController* PC, bool ReadyFlag);
    void UpdatePlayerSelectCharacter(const APlayerController* PC, FName CharacterRowName);
    
	void UpdateHostAddCharacterFromPlayer(const APlayerController* PC, FName CharacterRowName);
    void UpdateHostRemoveCharacterFromPlayer(const APlayerController* PC, FString CharacterInstanceId);


    void UpdateAddCharacterFromHost(FName CharacterRowName);
    void UpdateRemoveCharacterFromHost(FString CharacterInstanceId);
    void UpdateChangeCharacterTeamIndexFromHost(FString CharacterInstanceId, int32 NewTeamIndex);

public:

    FOnPlayerListChanged OnPlayerInfoChanged;

protected:

    UFUNCTION()
    void OnRep_PlayerLobbyInfos();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
