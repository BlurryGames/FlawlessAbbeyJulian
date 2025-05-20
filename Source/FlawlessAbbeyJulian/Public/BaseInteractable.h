#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemType.h"

#include "BaseInteractable.generated.h"

/**
 * @file BaseInteractable.h
 * @brief Declares the UBaseInteractable class, a base widget for interactable UI elements.
 *
 * This class provides a foundation for interactable UI widgets, exposing an item type property
 * for use in both C++ and Blueprints.
 */

/**
 * @class UBaseInteractable
 * @brief Base class for interactable UI widgets.
 *
 * Inherits from UUserWidget and provides an item type property for categorization and logic.
 * Marked as Blueprintable for use in Blueprints.
 */
UCLASS(Blueprintable)
class FLAWLESSABBEYJULIAN_API UBaseInteractable : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	/**
	 * @brief The type of item associated with this interactable widget.
	 *
	 * Editable in the editor and accessible in Blueprints.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	EItemType ItemType = EItemType::EMPTY;
};
