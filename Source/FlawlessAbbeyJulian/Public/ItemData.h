#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemData.generated.h"

/**
 * @file ItemData.h
 * @brief Defines the FItemData struct for representing item properties in data tables.
 *
 * This struct is used to store and manage item-related data such as name, description, icon, and material.
 * It is designed to be used with Unreal Engine's DataTable system and is accessible from both C++ and Blueprints.
 */

/**
 * @struct FItemData
 * @brief Structure that holds all relevant data for an item.
 *
 * Inherits from FTableRowBase to support usage in DataTables.
 * Marked as BlueprintType to allow use in Blueprints.
 */
USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()

	/** The display name of the item. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
	FText ItemName = FText::FromString("Empty");

	/** The description of the item. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
	FText ItemDescription = FText::FromString("");

	/** The icon representing the item. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
	UTexture2D* ItemIcon = nullptr;

	/** The material associated with the item. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
	UMaterial* ItemMaterial = nullptr;

	/** Default constructor. */
	FItemData() {}
};
