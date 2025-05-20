/**
 * @file UIUtilityLibrary.cpp
 * @brief Implements utility functions for retrieving display names for item and dialogue types.
 *
 * This file provides static helper functions for mapping item and dialogue enum values
 * to their corresponding display names using predefined maps.
 */

#include "UIUtilityLibrary.h"

/**
 * @brief Retrieves the display name for a given item type.
 *
 * Looks up the provided EItemType in the ItemNameMap and returns the associated FName.
 * If the item type is not found, returns NAME_None.
 *
 * @param ItemType The item type to look up.
 * @return The display name as an FName, or NAME_None if not found.
 */
const FName UUIUtilityLibrary::GetItemName(const EItemType& ItemType)
{
	const FName* ItemName = ItemNameMap.Find(ItemType);

	return ItemName ? *ItemName : NAME_None;
}

/**
 * @brief Retrieves the display name for a given dialogue type.
 *
 * Looks up the provided EDialogueType in the DialogueNameMap and returns the associated FName.
 * If the dialogue type is not found, returns NAME_None.
 *
 * @param DialogueType The dialogue type to look up.
 * @return The display name as an FName, or NAME_None if not found.
 */
const FName UUIUtilityLibrary::GetDialogueName(const EDialogueType& DialogueType)
{
	const FName* DialogueName = DialogueNameMap.Find(DialogueType);

	return DialogueName ? *DialogueName : NAME_None;
}
