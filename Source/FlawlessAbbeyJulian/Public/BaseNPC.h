#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DialogueType.h"

#include "BaseNPC.generated.h"

/**
 * @file BaseNPC.h
 * @brief Declares the ABaseNPC class, a base actor for non-player characters (NPCs).
 *
 * This class provides a foundation for NPCs in the game, including a mesh component
 * and a dialogue type property for interaction and dialogue management.
 */

/**
 * @class ABaseNPC
 * @brief Base class for non-player characters (NPCs).
 *
 * Inherits from AActor and provides core components and properties for NPCs.
 * Marked as Blueprintable for use in Blueprints.
 */
UCLASS(Blueprintable)
class FLAWLESSABBEYJULIAN_API ABaseNPC : public AActor
{
	GENERATED_BODY()
	
public:
	/** Default constructor. Initializes default values for this actor's properties. */
	ABaseNPC();

protected:
	/** The static mesh component representing the NPC's visual appearance. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh = nullptr;

	/** The dialogue type associated with this NPC, used for dialogue system integration. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dialogue Values")
	EDialogueType DialogueType = EDialogueType::EMPTY;
};
