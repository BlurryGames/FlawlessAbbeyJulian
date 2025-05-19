#include "BasePopup.h"

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

void UBasePopup::Enable_Implementation()
{
	if (!IsInViewport())
	{
		AddToPlayerScreen();
	}
}

void UBasePopup::Disable_Implementation()
{
	if (IsInViewport())
	{
		RemoveFromParent();
		Reset();
	}
}

void UBasePopup::Reset_Implementation()
{

}