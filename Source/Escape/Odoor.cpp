// Fill out your copyright notice in the Description page of Project Settings.


#include "Odoor.h"

// Sets default values for this component's properties
UOdoor::UOdoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOdoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens=GetWorld()->GetFirstPlayerController()->GetPawn();

	

	// ...
	
}

void UOdoor::OpenDoor()
{
	Owner = GetOwner();
	NewRotation = FRotator(0.0f, OpenAngle, 0.0f);
	Owner->SetActorRotation(NewRotation);
}

void UOdoor::CloseDoor()
{
	Owner = GetOwner();
	Owner->SetActorRotation(FRotator(0.0,-90.0, 0.0));
}


// Called every frame
void UOdoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > CloseDelay)
	{
		CloseDoor();
	}


	

	// ...
}

