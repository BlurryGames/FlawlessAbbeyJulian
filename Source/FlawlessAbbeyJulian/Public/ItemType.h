#pragma once

#include "ItemType.generated.h"

/**
 * @file ItemType.h
 * @brief Defines the EItemType enumeration for categorizing item types in the game.
 *
 * This enum is used to identify and differentiate between various item types
 * throughout the project, both in C++ and Blueprints.
 */

/**
 * @enum EItemType
 * @brief Enumerates all possible item types available in the game.
 *
 * Marked as BlueprintType to allow use in Blueprints.
 */
UENUM(BlueprintType)
enum class EItemType : uint8
{
	/** Represents an empty or uninitialized item slot. */
	EMPTY UMETA(DisplayName = "Empty"),

	/** Represents a statue item. */
	STATUE UMETA(DisplayName = "Statue"),

	/** Represents a bush item. */
	BUSH UMETA(DisplayName = "Bush"),

	/** Represents a table item. */
	TABLE UMETA(DisplayName = "Table"),

	/** Represents a chair item. */
	CHAIR UMETA(DisplayName = "Chair")
};
