// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "BaseBattlePlayerController.generated.h"

class UInputAction;
class UInputMappingContext;

class ABaseBattleHUD;
class ABattleCharacter;

UCLASS()
class TACTICAMORTIS_API ABaseBattlePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public: 

	ABaseBattlePlayerController();

protected:

	TObjectPtr<ABattleCharacter> SelectChar;

	TObjectPtr<ABaseBattleHUD> BattleHUD;

	

#pragma region Input

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveCameraAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ZoomCameraAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ResetCameraAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* SelectClickAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* InteractClickAction;



#pragma endregion


	FVector MovePoint;

	/** Current camera zoom level */
	float CameraZoom;

	/** Default camera zoom level */
	float DefaultZoom;

	/** Minimum allowed camera zoom level */
	UPROPERTY(EditAnywhere, Category = "Camera", meta = (ClampMin = 0, ClampMax = 10000))
	float MinZoomLevel = 1000.0f;

	/** Maximum allowed camera zoom level */
	UPROPERTY(EditAnywhere, Category = "Camera", meta = (ClampMin = 0, ClampMax = 10000))
	float MaxZoomLevel = 2500.0f;

	/** Scales zoom inputs by this value */
	UPROPERTY(EditAnywhere, Category = "Camera", meta = (ClampMin = 0, ClampMax = 1000))
	float ZoomScaling = 100.0f;
};
