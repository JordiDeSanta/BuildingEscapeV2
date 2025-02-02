// Copyright Jesús Bravo 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPEV2_API UOpenComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Timeline")
		void RotateOwner(FRotator Rotator);

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OpenDoor;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent CloseDoor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timeline")
		FRotator Position = FRotator(0.f, 90.f, 0.f);

	UPROPERTY(EditAnywhere, Category = "Open")
	ATriggerVolume* Plate = nullptr;

	UPROPERTY(EditAnywhere, Category = "Open")
	float TriggerMass = 30.f;

	void DetectMassInPlate();


};
