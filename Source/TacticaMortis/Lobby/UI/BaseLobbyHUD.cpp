// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseLobbyHUD.h"

#include "Blueprint/UserWidget.h"

#include "Lobby/CharacterSettings/LobbyPlayerController.h"
#include "Lobby/GameSettings/LobbyGameState.h"


void ABaseLobbyHUD::BeginPlay()
{
	//Super::BeginPlay(); странное поведение, вызываеться логика пузырёвого наследника 

	if (ALobbyGameState* LGSptr = Cast<ALobbyGameState>(
		GetWorld()->GetGameState())
		)
	{
		LGSptr->OnPlayerInfoChanged.AddUObject(this, &ABaseLobbyHUD::UpdateUI);

		MainWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), MainWidgetClass);
		MainWidget->AddToViewport();

		UpdateUI();
	}
	else
		ensure(false);

	Super::BeginPlay();
}

void ABaseLobbyHUD::UpdateWidgetPlayerName(const FString& NewPlayerName)
{
	if (ALobbyPlayerController* LPC = Cast<ALobbyPlayerController>(GetOwningPlayerController()))
		LPC->Server_UpdateName(NewPlayerName);
}

void ABaseLobbyHUD::UpdateWidgetPlayerTeamIndex(int32 NewTeamIndex)
{
	if (ALobbyPlayerController* LPC = Cast<ALobbyPlayerController>(GetOwningPlayerController()))
		LPC->Server_UpdateTeamIndex(NewTeamIndex);
}

void ABaseLobbyHUD::UpdateWidgetPlayerReadyFlag(bool NewReadyFlag)
{
	if (ALobbyPlayerController* LPC = Cast<ALobbyPlayerController>(GetOwningPlayerController()))
		LPC->Server_UpdateReadyFlag(NewReadyFlag);
}

void ABaseLobbyHUD::UpdateWidgetPlayerSelectCharacter(FName NewCharacterId)
{
	if (ALobbyPlayerController* LPC = Cast<ALobbyPlayerController>(GetOwningPlayerController()))
		LPC->Server_UpdateSelectCharacter(NewCharacterId);
}

void ABaseLobbyHUD::UpdateUI_Implementation()
{
	FString Name = GetOwner()->GetName();

	UE_LOG(LogTemp, Warning, TEXT("Geting update lobby info !"));

}

