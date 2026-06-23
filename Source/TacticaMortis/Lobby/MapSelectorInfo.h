#pragma once

#include "CoreMinimal.h"


#include "MapSelectorInfo.generated.h"


USTRUCT(BlueprintType)
struct FMapInfo : public FTableRowBase
{
    GENERATED_BODY();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText MapName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText MapDescription;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<UTexture2D> MapImage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<UWorld> Map;

};
