#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "ItemType.h"

#include "BaseItem.generated.h"

/**
 * @file BaseItem.h
 * @brief Declares the ABaseItem class, a base actor for interactable items in the game.
 *
 * This class provides core functionality for items, including mesh and capture components,
 * default transformation values, and interaction methods for rotation, zoom, and visibility.
 */

/**
 * @class ABaseItem
 * @brief Base class for interactable items in the game world.
 *
 * Inherits from AActor and provides properties and methods for item manipulation and interaction.
 * Marked as BlueprintType for use in Blueprints.
 */
UCLASS(BlueprintType)
class FLAWLESSABBEYJULIAN_API ABaseItem : public AActor
{
	GENERATED_BODY()

public:
	/** Default constructor. Initializes default values for this actor's properties. */
	ABaseItem();

protected:
	/** The static mesh component representing the item's visual appearance. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh = nullptr;

	/** The scene capture component used for rendering the item to a texture or UI. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneCaptureComponent2D* Capture = nullptr;

	/** The position to move the item to when it should be hidden. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item Values")
	FVector HiddenPosition = FVector(0.0f, 0.0f, 0.0f);

	/** The default rotation of the item, used for resetting its orientation. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Values")
	FRotator DefaultRotation = FRotator(0.0f, 0.0f, 0.0f);

	/** The default zoom value of the item, used for resetting its zoom. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Values")
	float DefaultZoom = 0.0f;

	/** The maximum allowed zoom offset for the item. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item Values", meta = (ClampMin = 0.0f, ClampMax = 100.0f))
	float ZoomLimit = 0.0f;

	/** The type of the item, used for categorization and logic. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item Values")
	EItemType ItemType = EItemType::EMPTY;

	/** Called when the game starts or when spawned. */
	virtual void BeginPlay() override;

	/**
	 * @brief Updates the item's rotation based on UI input.
	 * @param DeltaUI The change in UI input to apply to the rotation.
	 */
	UFUNCTION(BlueprintCallable, Category = "Item Interaction")
	void UpdateRotation(const FVector2D DeltaUI);

	/**
	 * @brief Updates the item's zoom based on input.
	 * @param DeltaZoom The amount to adjust the zoom by.
	 */
	UFUNCTION(BlueprintCallable, Category = "Item Interaction")
	void UpdateZoom(const float DeltaZoom);

	/**
	 * @brief Resets the item's rotation to its default value.
	 */
	UFUNCTION(BlueprintCallable, Category = "Item Interaction")
	void ResetRotation();

	/**
	 * @brief Resets the item's zoom to its default value.
	 */
	UFUNCTION(BlueprintCallable, Category = "Item Interaction")
	void ResetZoom();

	/**
	 * @brief Moves the item to its hidden position.
	 */
	UFUNCTION(BlueprintCallable, Category = "Item Interaction")
	void Hidde();

	/**
	 * @brief Checks if the given zoom offset is valid based on the zoom limit.
	 * @param ZoomOffset The zoom offset to validate.
	 * @return True if the zoom offset is within the allowed limit, false otherwise.
	 */
	bool ValidZoomOffset(const float& ZoomOffset) const;

	/** Sets the default rotation value based on the current mesh rotation. */
	void SetDefaultRotation();

	/** Sets the default zoom value based on the current capture component location. */
	void SetDefaultZoom();
};
