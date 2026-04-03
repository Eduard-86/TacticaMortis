#pragma once

#include "CoreMinimal.h"
#include "CharacterDataTypes.generated.h"

// 1. Базовые характеристики
USTRUCT(BlueprintType)
struct FCharacterAttributes : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 WeaponSkill = 30;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BallisticSkill = 30;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Strength = 30;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Toughness = 30;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Initiative = 30;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Agility = 30;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Dexterity = 30;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Intelligence = 30;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 WillPower = 30;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Fellowship = 30;
};

// 2. Структура оружия
USTRUCT(BlueprintType)
struct FWeaponData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName WeaponID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName WeaponName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Reach = 5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Damage = 5; // "1d10+2"

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<USkeletalMesh> WeaponMesh;
};

// 3. Промежуточная структура для передачи данных
USTRUCT(BlueprintType)
struct FCharacterBuildData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TeamIndex = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OwnerPlayerId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FCharacterAttributes Attributes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FWeaponData> Inventory;
};