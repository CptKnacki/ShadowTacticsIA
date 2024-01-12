// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardMovementComponent.h"
#include <Kismet/KismetMathLibrary.h>
#include <Kismet/KismetSystemLibrary.h>

UGuardMovementComponent::UGuardMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UGuardMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
	
}


void UGuardMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(canMove)
		Move();

	RotateTowardDestination();
}


void UGuardMovementComponent::Move()
{
	if (!pathToFollow)
		return;

	if (FVector::Distance(GetOwner()->GetActorLocation(), currentDestination) < 100.0f)
		currentDestination = pathToFollow->GetNextCheckpoint(currentDestination);
	

	FVector _location = FMath::VInterpConstantTo(GetOwner()->GetActorLocation(), currentDestination, GetWorld()->DeltaTimeSeconds, patrolSpeed);
	_location.Z = GetOwner()->GetActorLocation().Z;

	GetOwner()->SetActorLocation(_location);
}



void UGuardMovementComponent::RotateTowardDestination()
{
	
	FRotator _rotation = FMath::RInterpTo(GetOwner()->GetActorRotation(), UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), currentDestination), GetWorld()->DeltaTimeSeconds, 5);
	_rotation.Pitch = 0;
	_rotation.Roll = 0;

	GetOwner()->SetActorRotation(_rotation);
}



void UGuardMovementComponent::Init()
{
	if (!pathToFollow)
		return;

	currentDestination = pathToFollow->GetCheckpoints()[0]->GetActorLocation();
}
