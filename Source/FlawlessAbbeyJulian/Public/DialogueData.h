#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DialogueData.generated.h"

/**
 * @file DialogueData.h
 * @brief Defines the FDialogueData struct for representing dialogue entries in data tables.
 *
 * This struct is used to store and manage dialogue-related data such as the character's name and dialogue lines.
 * It is designed to be used with Unreal Engine's DataTable system and is accessible from both C++ and Blueprints.
 */

/**
 * @struct FDialogueData
 * @brief Structure that holds all relevant data for a dialogue entry.
 *
 * Inherits from FTableRowBase to support usage in DataTables.
 * Marked as BlueprintType to allow use in Blueprints.
 */
USTRUCT(BlueprintType)
struct FDialogueData : public FTableRowBase
{
	GENERATED_BODY()

	/** The name of the character speaking the dialogue. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue Data")
	FText CharacterName = FText::FromString("Empty");

	/** The lines of dialogue associated with this entry. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue Data")
	TArray<FString> DialogueLines = {};

	/** Default constructor. */
	FDialogueData() {}
};
