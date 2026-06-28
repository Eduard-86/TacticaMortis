// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "BattleGameMode.generated.h"


struct FPlayerLobbyInfo;
class ABattleCharacter;

UCLASS()
class TACTICAMORTIS_API ABattleGameMode : public AGameMode
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	void SpawnAllChars();

	TArray<FPlayerLobbyInfo> PlayerBattleData;

public:


	virtual void PostLogin(APlayerController* NewPlayer) override;

	UPROPERTY(EditDefaultsOnly, Category = "CharSetting")
	TSubclassOf<ABattleCharacter> CharClass;

	
};
