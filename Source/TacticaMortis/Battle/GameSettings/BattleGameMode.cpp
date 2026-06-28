
#include "BattleGameMode.h"

#include "CharacterSettings/BattleCharacter.h"
#include "GameFramework/PlayerState.h"

#include "Core/TacticaMortisGameInstance.h"
#include "Lobby/LobbyDataManager.h"
#include "Lobby/GameSettings/LobbyGameState.h"


void ABattleGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (ULobbyDataManager* DataManager = Cast<UTacticaMortisGameInstance>(GetGameInstance())->GetPlayersData())
	{
		PlayerBattleData = DataManager->PlayerLobbyInfos;

		DataManager->PlayerLobbyInfos.Empty();
		DataManager->RemoveFromRoot();
	}
	

	if (GetGameState<AGameState>() && GetGameState<AGameState>()->PlayerArray.Num() >= PlayerBattleData.Num())
	{
		SpawnAllChars();
	}

}

void ABattleGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (GetGameState<AGameState>() && GetGameState<AGameState>()->PlayerArray.Num() >= PlayerBattleData.Num())
	{
		SpawnAllChars();
	}
}

void ABattleGameMode::SpawnAllChars()
{
	for (auto PlayerData : PlayerBattleData)
	{

		TObjectPtr<APlayerState> PlayerState = *GetGameState<AGameState>()->PlayerArray.FindByPredicate(
			[&PlayerData](const TObjectPtr<APlayerState>& PlayerState)
			{
				return PlayerData.PlayerUniqueId == PlayerState->GetUniqueId().ToString();
			});

		if (PlayerData.PlayerCharacterRowName != FName("None"))
		{
			ABattleCharacter* Character = GetWorld()->SpawnActor<ABattleCharacter>(
				CharClass,
				FVector(0, 0, 100),
				FRotator::ZeroRotator
			);

			Character->SetOwner(PlayerState->GetPlayerController());

			Character->TeamIndex = PlayerData.TeamIndex;
			Character->CharRowName = PlayerData.PlayerCharacterRowName;
		}

		for (auto Char : PlayerData.AssignedCharacterRowNamesFromHost)
		{
			ABattleCharacter* Character = GetWorld()->SpawnActor<ABattleCharacter>(
				CharClass,
				FVector(0, 0, 100),
				FRotator::ZeroRotator
			);

			Character->SetOwner(PlayerState->GetPlayerController());

			Character->TeamIndex = Char.TeamIndex;
			Character->CharRowName = Char.RowName;

		}
	}

}