// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseLobbyHUD.h"

#include "Blueprint/UserWidget.h"

#include "Lobby/PlayerSettings/LobbyPlayerController.h"
#include "Lobby/GameSettings/LobbyGameState.h"


void ABaseLobbyHUD::BeginPlay()
{
	//Super::BeginPlay(); странное поведение, вызываеться логика пузырёвого наследника 

	if (ALobbyGameState* LGSptr = Cast<ALobbyGameState>(
		GetWorld()->GetGameState())
		)
	{
		LGSptr->OnPlayerInfoChanged.AddUObject(this, &ABaseLobbyHUD::UpdateUI);

		if (MainWidgetClass.Get())
		{
			MainWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), MainWidgetClass);
			MainWidget->AddToViewport();

			UpdateUI();
		}
	}
	else
		ensure(false);

	Super::BeginPlay();
}

void ABaseLobbyHUD::UpdateUI_Implementation()
{
	FString Name = GetOwner()->GetName();

	UE_LOG(LogTemp, Warning, TEXT("Geting update lobby info !"));

}

