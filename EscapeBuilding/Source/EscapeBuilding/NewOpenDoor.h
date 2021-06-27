// Copyright PolygonLantern 2021

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "NewOpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEBUILDING_API UNewOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNewOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
	float TargetYaw = 90.f;

	FRotator DoorRotator;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* DoorTrigger;

	UPROPERTY(EditAnywhere)
	AActor* ActorThatTriggers;
	
protected:
	void OpenDoor(float DeltaTime);
};
