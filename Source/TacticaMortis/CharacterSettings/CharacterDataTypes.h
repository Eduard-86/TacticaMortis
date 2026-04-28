#pragma once

#include "CoreMinimal.h"
#include "Runtime\RenderCore\Public\RenderResource.h"

#include "CharacterDataTypes.generated.h"

UENUM(BlueprintType)
enum class ERace : uint8
{
    //None							UMETA(DisplayName = "None"),
    Human,
    Elf,
    Dwarf,
};


// 1. Базовые характеристики
USTRUCT(BlueprintType)
struct FCharacterAttributes : public FTableRowBase
{
    GENERATED_BODY()

#pragma region CharacteriStats
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
#pragma endregion CharacteriStats

#pragma region Other

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ERace Race;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Wounds = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BonusWounds = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Speed = 30;

    //UPROPERTY(EditAnywhere, BlueprintReadWrite)
    //int32 Resistance = 30;

#pragma endregion Other


};

static void CalculateWounds(const FCharacterAttributes& CharacterAttributes)
{
	switch (CharacterAttributes.Race)
	{
		case ERace::Dwarf :
		{
			break;
		}
        case ERace::Elf:
        {
            break;
        }
        case ERace::Human:
        {
            break;
        }

        default:
		{
			break;
		}
	}
}

USTRUCT(BlueprintType)
struct FCharacterSkill : public FTableRowBase
{
    GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName SkillName = "Avoidance";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BonusValue = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName BaseAttribute = "Agility";

};

UENUM(BlueprintType)
enum class EWeaponHandsType : uint8
{
    //None							UMETA(DisplayName = "None"),
    One_MainHand,
    One_NonMainHand,
    TwoHands,
};

// 2. Структура оружия
USTRUCT(BlueprintType)
struct FWeaponData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    uint8 ID = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName WeaponName = "Axe";
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Reach = 5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Damage = 5; // "1d10+2"

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EWeaponHandsType HandsType = EWeaponHandsType::One_MainHand;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<USkeletalMesh> WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> WeaponIcon;

};

UENUM(BlueprintType)
enum class EArmoredBodyType : uint8
{
    //None							UMETA(DisplayName = "None"),
    Hands_Armor,
    Head_Armor,
    Body_Armor,
    Legs_Armor,
};

USTRUCT(BlueprintType)
struct FArmorData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ArmorName = "SteelHelm";

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Protection = 3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EArmoredBodyType ArmorBodyType = EArmoredBodyType::Head_Armor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<USkeletalMesh> ArmorMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<UTexture2D> ArmorIcon;

};

// 3. Промежуточная структура для передачи данных
USTRUCT(BlueprintType)
struct FCharacterData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName CharacterId = "Warrior_Male_0";

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterName = "Warrior";

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<USkeletalMesh> CharacterBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<UTexture2D> CharacterIcon;


    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TeamIndex = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OwnerPlayerUniqueId = "NONE";

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FCharacterAttributes Attributes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FCharacterSkill> Skills;


    UPROPERTY(EditAnywhere, BlueprintReadWrite,
        meta = (RowType = "/Script/TacticaMortis.WeaponData"))
    FDataTableRowHandle   MainWeapon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite,
        meta = (RowType = "/Script/TacticaMortis.WeaponData"))
    FDataTableRowHandle   NonMainWeapon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite,
        meta = (RowType = "/Script/TacticaMortis.WeaponData"))
    TArray<FDataTableRowHandle> OtherWeapon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite,
        meta = (RowType = "/Script/TacticaMortis.ArmorData"))
    TArray<FDataTableRowHandle> Armors;

};