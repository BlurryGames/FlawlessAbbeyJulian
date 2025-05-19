// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "ItemType.h"

#include "BaseItem.generated.h"

UCLASS(BlueprintType)
class FLAWLESSABBEYJULIAN_API ABaseItem : public AActor
{
	GENERATED_BODY()

public:
	ABaseItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneCaptureComponent2D* Capture = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item Values")
	FVector HiddenPosition = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Values")
	FRotator DefaultRotation = FRotator(0.0f, 0.0f, 0.0f);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Values")
	float DefaultZoom = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item Values", meta = (ClampMin = 0.0f, ClampMax = 100.0f))
	float ZoomLimit = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item Values")
	EItemType ItemType = EItemType::EMPTY;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Item Interaction")
	void UpdateRotation(const FVector2D DeltaUI);

	UFUNCTION(BlueprintCallable, Category = "Item Interaction")
	void UpdateZoom(const float DeltaZoom);

	UFUNCTION(BlueprintCallable, Category = "Item Interaction")
	void ResetRotation();

	UFUNCTION(BlueprintCallable, Category = "Item Interaction")
	void ResetZoom();

	UFUNCTION(BlueprintCallable, Category = "Item Interaction")
	void Hidde();

	bool ValidZoomOffset(const float& ZoomOffset) const;

	void SetDefaultRotation();
	void SetDefaultZoom();
};
