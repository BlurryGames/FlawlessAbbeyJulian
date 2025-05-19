#pragma once

#include "ItemType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EItemType : uint8
{
	EMPTY UMETA(DisplayName = "Empty"), 
	STATUE UMETA(DisplayName = "Statue"), 
	BUSH UMETA(DisplayName = "Bush"), 
	TABLE UMETA(DisplayName = "Table"), 
	CHAIR UMETA(DisplayName = "Chair")
};
