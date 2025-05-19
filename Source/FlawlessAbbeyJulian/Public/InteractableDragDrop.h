#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "ItemType.h"

#include "InteractableDragDrop.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FLAWLESSABBEYJULIAN_API UInteractableDragDrop : public UDragDropOperation
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, Category = "Drag Drop", meta = (AllowPrivateAccess = "true"))
	EItemType RowItemType = EItemType::EMPTY;
};
