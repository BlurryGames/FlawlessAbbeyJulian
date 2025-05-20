#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ItemType.h"
#include "DialogueType.h"

#include "UIUtilityLibrary.generated.h"

/**
 * @file UIUtilityLibrary.h
 * @brief Utility library for UI-related helper functions and mappings.
 * 
 * This library provides static functions and maps to retrieve display names for item and dialogue types.
 * All functions are BlueprintPure for easy use in Blueprints.
 */

/**
 * @class UUIUtilityLibrary
 * @brief Static utility class for UI-related helper functions.
 * 
 * Provides static methods to get display names for item and dialogue types.
 * Designed for use in both C++ and Blueprints.
 */
UCLASS()
class FLAWLESSABBEYJULIAN_API UUIUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/**
	 * @brief Returns the display name for a given item type.
	 * @param ItemType The item type to look up.
	 * @return The display name as an FName.
	 */
	UFUNCTION(BlueprintPure, Category = "Item Utility")
	static const FName GetItemName(const EItemType& ItemType);

	/**
	 * @brief Returns the display name for a given dialogue type.
	 * @param DialogueType The dialogue type to look up.
	 * @return The display name as an FName.
	 */
	UFUNCTION(BlueprintPure, Category = "Dialogue Utility")
	static const FName GetDialogueName(const EDialogueType& DialogueType);
};

/**
 * @brief Mapping of EItemType to their display names.
 * 
 * Used internally by UUIUtilityLibrary to provide names realted with corresponding data table for item types.
 */
static const TMap<EItemType, FName> ItemNameMap = {
	{ EItemType::EMPTY, FName("Empty") }, 
	{ EItemType::STATUE, FName("Statue") }, 
	{ EItemType::BUSH, FName("Bush") }, 
	{ EItemType::TABLE, FName("Table") }, 
	{ EItemType::CHAIR, FName("Chair") }
};

/**
 * @brief Mapping of EDialogueType to their display names.
 * 
 * Used internally by UUIUtilityLibrary to provide realted with corresponding data table for dialogue types.
 */
static const TMap<EDialogueType, FName> DialogueNameMap = {
	{ EDialogueType::EMPTY, FName("Empty") }, 
	{ EDialogueType::CUBE, FName("Cube") }
};