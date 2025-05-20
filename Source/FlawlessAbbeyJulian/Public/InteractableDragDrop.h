#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "ItemType.h"

#include "InteractableDragDrop.generated.h"

/**
 * @file InteractableDragDrop.h
 * @brief Defines the UInteractableDragDrop class for handling drag-and-drop operations with interactable items.
 *
 * This class extends UDragDropOperation to support item type tracking during drag-and-drop UI interactions.
 */

/**
 * @class UInteractableDragDrop
 * @brief Drag-and-drop operation class for interactable items in the UI.
 *
 * Stores the item type being dragged, allowing for type-specific logic during drag-and-drop events.
 * Marked as BlueprintType for use in Blueprints.
 */
UCLASS(BlueprintType)
class FLAWLESSABBEYJULIAN_API UInteractableDragDrop : public UDragDropOperation
{
	GENERATED_BODY()
	
protected:
	/** The type of the item being dragged. Defaults to EMPTY. */
	UPROPERTY(BlueprintReadWrite, Category = "Drag Drop", meta = (ExposeOnSpawn = "true"))
	EItemType RowItemType = EItemType::EMPTY;
};
