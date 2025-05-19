#include "UIUtilityLibrary.h"

const FName UUIUtilityLibrary::GetItemName(const EItemType& ItemType)
{
	const FName* ItemName = ItemNameMap.Find(ItemType);

	return ItemName ? *ItemName : NAME_None;
}

const FName UUIUtilityLibrary::GetDialogueName(const EDialogueType& DialogueType)
{
	const FName* DialogueName = DialogueNameMap.Find(DialogueType);

	return DialogueName ? *DialogueName : NAME_None;
}
