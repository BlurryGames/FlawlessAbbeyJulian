/**
 * @file BaseNPC.cpp
 * @brief Implements the ABaseNPC class, a base actor for non-player characters (NPCs).
 *
 * This file defines the constructor for ABaseNPC, setting up the root and mesh components.
 */

#include "BaseNPC.h"

/**
 * @brief Default constructor for ABaseNPC.
 *
 * Initializes the root scene component and the static mesh component for the NPC.
 * The mesh is attached to the root component.
 */
ABaseNPC::ABaseNPC()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CharacterMesh"));
	Mesh->SetupAttachment(RootComponent);
}