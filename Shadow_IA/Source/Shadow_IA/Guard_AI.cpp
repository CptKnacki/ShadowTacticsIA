// Fill out your copyright notice in the Description page of Project Settings.


#include "Guard_AI.h"

// Sets default values
AGuard_AI::AGuard_AI()
{
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<USkeletalMeshComponent>("skeletal mesh");
	RootComponent = mesh;

	movement = CreateDefaultSubobject<UGuardMovementComponent>("movement");

	AddOwnedComponent(movement);
}

void AGuard_AI::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGuard_AI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGuard_AI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

