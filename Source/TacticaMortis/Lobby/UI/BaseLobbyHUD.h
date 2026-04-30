// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BaseLobbyHUD.generated.h"

/**
 * 
 */

class ALobbyGameState;

UCLASS(Abstract)
class TACTICAMORTIS_API ABaseLobbyHUD : public AHUD
{
	GENERATED_BODY()

public:

	UFUNCTION()
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void UpdateUI();

	
public:

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ALobbyGameState> LobbyGameState;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> MainWidgetClass;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UUserWidget> MainWidget;

};

