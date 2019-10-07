// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	PlayerViewLocation;
	PlayerViewRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewLocation,
		OUT PlayerViewRotation
	);
	
	FString Rotated = PlayerViewRotation.ToString();
	//Get the player view point
	//Ray Cast to find what im looking at
	//see what gets hit

	/*UE_LOG(LogTemp, Warning, TEXT("Location: %s, Position: %str"),
		*PlayerViewLocation.ToString(),
		*PlayerViewRotation.ToString()
	);*/

	FVector LineTraceEnd = PlayerViewLocation + PlayerViewRotation.Vector() * Reach;
	
	DrawDebugLine(
		GetWorld(),
		PlayerViewLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		5.f
	);
	
	//steup query param
	FCollisionQueryParams TraceParam(FName(TEXT("")), false, GetOwner());
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParam

	);
	
	AActor* ActorHit = Hit.GetActor();
	
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *(ActorHit->GetName()));
	}
	
}

