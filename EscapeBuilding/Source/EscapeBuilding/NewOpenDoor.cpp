// Copyright PolygonLantern 2021


#include "NewOpenDoor.h"

// Sets default values for this component's properties
UNewOpenDoor::UNewOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
// Called when the game starts
void UNewOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw += InitialYaw;
	
}

// Called every frame
void UNewOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (DoorTrigger->IsOverlappingActor(ActorThatTriggers))
	{
		OpenDoor(DeltaTime);	
	}
	
	
}

void UNewOpenDoor::OpenDoor(float DeltaTime)
{
	CurrentYaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 2);
	
	DoorRotator.Yaw = CurrentYaw;

	GetOwner()->SetActorRotation(DoorRotator);
}

