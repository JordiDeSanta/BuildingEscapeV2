// Copyright Jesús Bravo 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
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
		FDoorEvent OpenEvent;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent CloseEvent;

private:
	UPROPERTY(EditAnywhere, Category = "Timeline")
		float OpenCloseTime = 2.f;
		
};
