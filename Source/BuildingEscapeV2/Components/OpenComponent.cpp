// Copyright Jesús Bravo 2020


#include "OpenComponent.h"

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

	OpenDoor.Broadcast();
	
}


// Called every frame
void UOpenComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UOpenComponent::RotateOwner(FRotator Rotator)
{
	GetOwner()->SetActorRotation(Rotator);
	return;
}


