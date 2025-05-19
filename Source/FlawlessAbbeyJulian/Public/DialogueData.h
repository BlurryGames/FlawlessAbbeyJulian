#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DialogueData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FDialogueData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue Data")
	FText CharacterName = FText::FromString("Empty");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue Data")
	TArray<FString> DialogueLines = {};

	FDialogueData() {}
};
