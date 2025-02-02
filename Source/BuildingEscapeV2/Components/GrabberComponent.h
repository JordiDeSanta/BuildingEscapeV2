// Copyright Jesús Bravo 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GrabberComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BUILDINGESCAPEV2_API UGrabberComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrabberComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Grab")
		float Reach = 200.f;

	UPROPERTY(EditAnywhere, Category = "Impulse")
		float LaunchForce = 100.f;

	UPROPERTY()
		UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UPROPERTY()
		UInputComponent* InputComponent = nullptr;

	void Grab();
	void Release();
	void Impulse();
	void FindPhysicsHandle();
	void SetupInputComponent();

	// Return the first Actor within reach with physics body.
	FHitResult GetFirstPhysicsBodyInReach() const;

	// Return The Line Trace End.
	FVector GetPlayersReach() const;

	// Get Players Position In World.
	FVector GetPlayersWorldPos() const;
};
