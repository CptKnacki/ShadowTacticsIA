// Fill out your copyright notice in the Description page of Project Settings.


#include "MainShadowCharacter.h"

// Sets default values
AMainShadowCharacter::AMainShadowCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainShadowCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainShadowCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainShadowCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

