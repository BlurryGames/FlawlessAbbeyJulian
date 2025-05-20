#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BasePopup.generated.h"

/**
 * @file BasePopup.h
 * @brief Declares the UBasePopup class, a reusable base widget for popup UI elements.
 *
 * This class provides a base for popup widgets, exposing core popup functionality
 * to both C++ and Blueprints. All functions are BlueprintNativeEvent, allowing
 * them to be overridden in Blueprints or derived C++ classes.
 */

/**
 * @class UBasePopup
 * @brief Base class for popup UI widgets.
 *
 * Inherits from UUserWidget and provides core popup control functions.
 * Marked as Blueprintable for use in Blueprints.
 */
UCLASS(Blueprintable)
class FLAWLESSABBEYJULIAN_API UBasePopup : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	/**
	 * @brief Toggles the popup's visibility on the viewport.
	 *
	 * Can be overridden in Blueprints or C++ to customize popup behavior.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Popup UI")
	void Popup();

	/**
	 * @brief Enables the popup by adding it to the viewport.
	 *
	 * Can be overridden in Blueprints or C++ to customize enable behavior.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Popup UI")
	void Enable();

	/**
	 * @brief Disables the popup by removing it from the viewport.
	 *
	 * Can be overridden in Blueprints or C++ to customize disable behavior.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Popup UI")
	void Disable();

	/**
	 * @brief Resets the internal state of the popup.
	 *
	 * Intended to be overridden for custom reset logic.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Popup UI")
	void Reset();
};
