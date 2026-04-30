// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/GameSettings/LobbyGameMode.h"
#include "LobbyGameState.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	//GetGameState<ALobbyGameState>()->AddNewPlayer(NewPlayer);

	ALobbyGameState* GSPtr = GetGameState<ALobbyGameState>();

	if (GSPtr)
	{
		GSPtr->AddNewPlayer(NewPlayer);
	}
	else
	{
		FTimerHandle TimeHandler;
		GetWorldTimerManager().SetTimer(TimeHandler, [this, NewPlayer]()
			{
				ALobbyGameState* GSPtr = GetGameState<ALobbyGameState>();
				if (IsValid(GSPtr) && IsValid(NewPlayer))
				{
					GSPtr->AddNewPlayer(NewPlayer);
					
				}

			}, 0.5f, false);
	}

}

void ALobbyGameMode::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
	Super::HandleStartingNewPlayer_Implementation(NewPlayer);

	
	//->AddNewPlayer(NewPlayer);

}
