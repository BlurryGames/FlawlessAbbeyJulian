#include "BaseItem.h"

ABaseItem::ABaseItem()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	Mesh->SetupAttachment(RootComponent);

	Capture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCapture"));
	Capture->SetupAttachment(RootComponent);
}

void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	SetDefaultRotation();
	SetDefaultZoom();
}

void ABaseItem::UpdateRotation(const FVector2D DeltaUI)
{
	if (IsValid(Mesh))
	{
		Mesh->AddLocalRotation(FRotator(0.0f, DeltaUI.Y, DeltaUI.X));
	}
}

void ABaseItem::UpdateZoom(const float DeltaZoom)
{
	if (IsValid(Capture) && ValidZoomOffset(DeltaZoom))
	{
		Capture->AddLocalOffset(FVector(DeltaZoom, 0.0f, 0.0f));
	}
}

void ABaseItem::ResetRotation()
{
	if (IsValid(Mesh))
	{
		Mesh->SetRelativeRotation(DefaultRotation);
	}
}

void ABaseItem::ResetZoom()
{
	if (IsValid(Capture))
	{
		const FVector& CurrentLocation = Capture->GetRelativeLocation();
		Capture->SetRelativeLocation(FVector(DefaultZoom, CurrentLocation.Y, CurrentLocation.Z));
	}
}

void ABaseItem::Hidde()
{
	SetActorLocation(HiddenPosition);
}

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

void ABaseItem::SetDefaultRotation()
{
	if (IsValid(Mesh))
	{
		DefaultRotation = Mesh->GetRelativeRotation();
	}
}

void ABaseItem::SetDefaultZoom()
{
	if (IsValid(Capture))
	{
		DefaultZoom = Capture->GetRelativeLocation().X;
	}
}
