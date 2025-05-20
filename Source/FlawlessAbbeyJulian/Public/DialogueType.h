#pragma once

#include "DialogueType.generated.h"

/**
 * @file DialogueType.h
 * @brief Defines the EDialogueType enumeration for categorizing dialogue types in the game.
 *
 * This enum is used to identify and differentiate between various dialogue types
 * throughout the project, both in C++ and Blueprints.
 */

/**
 * @enum EDialogueType
 * @brief Enumerates all possible dialogue types available in the game.
 *
 * Marked as BlueprintType to allow use in Blueprints.
 */
UENUM(BlueprintType)
enum class EDialogueType : uint8
{
	/** Represents an empty or uninitialized dialogue entry. */
	EMPTY UMETA(DisplayName = "Empty"),

	/** Represents a dialogue entry related to a cube. */
	CUBE UMETA(DisplayName = "Cube")
};