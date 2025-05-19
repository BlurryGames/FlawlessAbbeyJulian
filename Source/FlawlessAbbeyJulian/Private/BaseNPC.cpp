#include "BaseNPC.h"

ABaseNPC::ABaseNPC()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CharacterMesh"));
	Mesh->SetupAttachment(RootComponent);
}