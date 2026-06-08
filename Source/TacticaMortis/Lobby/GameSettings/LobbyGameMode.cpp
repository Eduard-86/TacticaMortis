// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/GameSettings/LobbyGameMode.h"
#include "LobbyGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Lobby/UI/ClientLobbyHUD.h"
#include "Lobby/UI/HostLobbyHUD.h"

APlayerController* ALobbyGameMode::SpawnPlayerController(ENetRole InRemoteRole, const FString& Options)
{
	//bool bIsHost = UGameplayStatics::HasOption(Options, TEXT("IsHost"));

	TSubclassOf<APlayerController> PCClassToSpawn = nullptr;

	if (InRemoteRole == ROLE_SimulatedProxy)
	{
		PCClassToSpawn = HostPlayerControllerClass;
		UE_LOG(LogTemp, Log, TEXT("Spawning Host Player Controller"));
	}
	else if (InRemoteRole == ROLE_AutonomousProxy)
	{
		PCClassToSpawn = ClientPlayerControllerClass;
		UE_LOG(LogTemp, Log, TEXT("Spawning Client Player Controller"));
	}
	else
	{
		PCClassToSpawn = PlayerControllerClass;
		UE_LOG(LogTemp, Warning, TEXT("Spawning fallback Player Controller with role %d"), (int32)InRemoteRole);
	}

	if (!PCClassToSpawn)
	{
		PCClassToSpawn = PlayerControllerClass;
	}


	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnInfo.ObjectFlags |= RF_Transient;
	SpawnInfo.Instigator = GetInstigator();

	APlayerController* NewPC = GetWorld()->SpawnActor<APlayerController>(PCClassToSpawn, SpawnInfo);


	if (NewPC)
	{
		if (InRemoteRole == ROLE_SimulatedProxy)
		{
			NewPC->SetAsLocalPlayerController();
		}

		NewPC->SetReplicates(true);
	}

	return NewPC;

	//return Super::SpawnPlayerController(InRemoteRole, Options);
}


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
		//ALobbyGameState* GSPtr = GetGameState<ALobbyGameState>();

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

	if (NewPlayer->IsLocalPlayerController())
	{
		if (HostHUD.Get())
			NewPlayer->ClientSetHUD(HostHUD);
	}
	else
	{
		if (ClientHUD.Get())
			NewPlayer->ClientSetHUD(ClientHUD);
	}

}

void ALobbyGameMode::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
	Super::HandleStartingNewPlayer_Implementation(NewPlayer);

	
	//->AddNewPlayer(NewPlayer);

}
