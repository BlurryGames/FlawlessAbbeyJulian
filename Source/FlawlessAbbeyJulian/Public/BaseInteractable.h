#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemType.h"

#include "BaseInteractable.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FLAWLESSABBEYJULIAN_API UBaseInteractable : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	EItemType ItemType = EItemType::EMPTY;
};
