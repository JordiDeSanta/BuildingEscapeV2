// Copyright Jesús Bravo 2020


#include "OpenComponent.h"

#define OUT

// Sets default values for this component's properties
UOpenComponent::UOpenComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UOpenComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	DetectMassInPlate();
}

void UOpenComponent::RotateOwner(FRotator Rotator)
{
	GetOwner()->SetActorRotation(Rotator);
	return;
}

void UOpenComponent::DetectMassInPlate()
{
	float TotalMass = 0.f;

	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!Plate) { return; }
	Plate->GetOverlappingActors(OUT OverlappingActors);

	// Iterate through them adding their masses
	for (const auto& Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	if (TotalMass >= TriggerMass)
	{
		OpenDoor.Broadcast();
		return;
	}
	else
	{
		CloseDoor.Broadcast();
		return;
	}

	return;
}


