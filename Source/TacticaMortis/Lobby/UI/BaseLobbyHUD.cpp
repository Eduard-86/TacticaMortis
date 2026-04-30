// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseLobbyHUD.h"

#include "Blueprint/UserWidget.h"
#include "Lobby/GameSettings/LobbyGameState.h"


void ABaseLobbyHUD::BeginPlay()
{
	Super::BeginPlay();

	ALobbyGameState* LGSptr = Cast<ALobbyGameState>(
		GetWorld()->GetGameState()
	);

	if (LGSptr)
	{
		LobbyGameState = LGSptr;
		
		LobbyGameState->OnPlayerInfoChanged.AddUObject(this, &ABaseLobbyHUD::UpdateUI);

		MainWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), MainWidgetClass);
		MainWidget->AddToViewport();

		UpdateUI();
	}
	else
		ensure(false);
}

void ABaseLobbyHUD::UpdateUI_Implementation()
{

}

