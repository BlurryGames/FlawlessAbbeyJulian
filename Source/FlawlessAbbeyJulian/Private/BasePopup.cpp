#include "BasePopup.h"

/**
 * @brief Toggles the popup's visibility on the viewport.
 *
 * If the popup is already in the viewport, it will be removed and reset.
 * Otherwise, it will be added to the player's screen.
 *
 * @see UUserWidget::AddToPlayerScreen
 * @see UUserWidget::RemoveFromParent
 */
void UBasePopup::Popup_Implementation()
{
	if (IsInViewport())
	{
		RemoveFromParent();
		Reset();
	}
	else
	{
		AddToPlayerScreen();
	}
}

/**
 * @brief Enables the popup by adding it to the viewport if it is not already present.
 *
 * @see UUserWidget::AddToPlayerScreen
 */
void UBasePopup::Enable_Implementation()
{
	if (!IsInViewport())
	{
		AddToPlayerScreen();
	}
}

/**
 * @brief Disables the popup by removing it from the viewport and resetting its state.
 *
 * @see UUserWidget::RemoveFromParent
 */
void UBasePopup::Disable_Implementation()
{
	if (IsInViewport())
	{
		RemoveFromParent();
		Reset();
	}
}

/**
 * @brief Resets the internal state of the popup.
 *
 * This function is intended to be overridden in Blueprints or derived C++ classes.
 * By default, it does nothing.
 */
void UBasePopup::Reset_Implementation()
{

}