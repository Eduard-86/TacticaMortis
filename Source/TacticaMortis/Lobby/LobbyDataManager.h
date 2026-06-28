// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LobbyDataManager.generated.h"

struct FPlayerLobbyInfo;

UCLASS()
class TACTICAMORTIS_API ULobbyDataManager : public UObject
{
	GENERATED_BODY()

public:

	TArray<FPlayerLobbyInfo> PlayerLobbyInfos;
	
};
