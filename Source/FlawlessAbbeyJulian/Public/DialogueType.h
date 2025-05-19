#pragma once

#include "DialogueType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EDialogueType : uint8
{
	EMPTY UMETA(DisplayName = "Empty"), 
	CUBE UMETA(DisplayName = "Cube")
};