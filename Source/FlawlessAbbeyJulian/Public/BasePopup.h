#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BasePopup.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FLAWLESSABBEYJULIAN_API UBasePopup : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Popup UI")
	void Popup();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Popup UI")
	void Enable();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Popup UI")
	void Disable();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Popup UI")
	void Reset();
};
