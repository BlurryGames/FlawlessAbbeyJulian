#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ItemType.h"
#include "DialogueType.h"

#include "UIUtilityLibrary.generated.h"

/**
 * 
 */
UCLASS()
class FLAWLESSABBEYJULIAN_API UUIUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Item Utility")
	static const FName GetItemName(const EItemType& ItemType);

	UFUNCTION(BlueprintPure, Category = "Dialogue Utility")
	static const FName GetDialogueName(const EDialogueType& DialogueType);
};

static const TMap<EItemType, FName> ItemNameMap = {
	{ EItemType::EMPTY, FName("Empty") }, 
	{ EItemType::STATUE, FName("Statue") }, 
	{ EItemType::BUSH, FName("Bush") }, 
	{ EItemType::TABLE, FName("Table") }, 
	{ EItemType::CHAIR, FName("Chair") }
};

static const TMap<EDialogueType, FName> DialogueNameMap = {
	{ EDialogueType::EMPTY, FName("Empty") }, 
	{ EDialogueType::CUBE, FName("Cube") }
};