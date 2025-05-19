#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DialogueType.h"

#include "BaseNPC.generated.h"

UCLASS(Blueprintable)
class FLAWLESSABBEYJULIAN_API ABaseNPC : public AActor
{
	GENERATED_BODY()
	
public:
	ABaseNPC();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dialogue Values")
	EDialogueType DialogueType = EDialogueType::EMPTY;
};
