/**
 * @file BaseItem.cpp
 * @brief Implements the ABaseItem class, providing core logic for interactable items in the game.
 *
 * This file defines the constructor and member functions for ABaseItem, including
 * initialization, rotation and zoom manipulation, and state reset logic.
 */

#include "BaseItem.h"

/**
 * @brief Default constructor for ABaseItem.
 *
 * Initializes the root scene component, static mesh component, and scene capture component.
 * Sets up component attachment hierarchy.
 */
ABaseItem::ABaseItem()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	Mesh->SetupAttachment(RootComponent);

	Capture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCapture"));
	Capture->SetupAttachment(RootComponent);
}

/**
 * @brief Called when the game starts or when spawned.
 *
 * Initializes the default rotation and zoom values for the item.
 */
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	SetDefaultRotation();
	SetDefaultZoom();
}

/**
 * @brief Updates the item's rotation based on UI input.
 * @param DeltaUI The change in UI input to apply to the rotation (X and Y axes).
 */
void ABaseItem::UpdateRotation(const FVector2D DeltaUI)
{
	if (IsValid(Mesh))
	{
		Mesh->AddLocalRotation(FRotator(0.0f, DeltaUI.Y, DeltaUI.X));
	}
}

/**
 * @brief Updates the item's zoom based on input.
 * @param DeltaZoom The amount to adjust the zoom by.
 */
void ABaseItem::UpdateZoom(const float DeltaZoom)
{
	if (IsValid(Capture) && ValidZoomOffset(DeltaZoom))
	{
		Capture->AddLocalOffset(FVector(DeltaZoom, 0.0f, 0.0f));
	}
}

/**
 * @brief Resets the item's rotation to its default value.
 */
void ABaseItem::ResetRotation()
{
	if (IsValid(Mesh))
	{
		Mesh->SetRelativeRotation(DefaultRotation);
	}
}

/**
 * @brief Resets the item's zoom to its default value.
 */
void ABaseItem::ResetZoom()
{
	if (IsValid(Capture))
	{
		const FVector& CurrentLocation = Capture->GetRelativeLocation();
		Capture->SetRelativeLocation(FVector(DefaultZoom, CurrentLocation.Y, CurrentLocation.Z));
	}
}

/**
 * @brief Moves the item to its hidden position.
 */
void ABaseItem::Hidde()
{
	SetActorLocation(HiddenPosition);
}

/**
 * @brief Checks if the given zoom offset is valid based on the zoom limit.
 * @param ZoomOffset The zoom offset to validate.
 * @return True if the zoom offset is within the allowed limit, false otherwise.
 */
bool ABaseItem::ValidZoomOffset(const float& ZoomOffset) const
{
	bool bValid = false;
	if (IsValid(Capture))
	{
		float CurrentZoom = Capture->GetRelativeLocation().X - DefaultZoom;
		bValid = abs(CurrentZoom + ZoomOffset) < ZoomLimit;
	}

	return bValid;
}

/**
 * @brief Sets the default rotation value based on the current mesh rotation.
 */
void ABaseItem::SetDefaultRotation()
{
	if (IsValid(Mesh))
	{
		DefaultRotation = Mesh->GetRelativeRotation();
	}
}

/**
 * @brief Sets the default zoom value based on the current capture component location.
 */
void ABaseItem::SetDefaultZoom()
{
	if (IsValid(Capture))
	{
		DefaultZoom = Capture->GetRelativeLocation().X;
	}
}
