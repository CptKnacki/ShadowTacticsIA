// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GuardPath.h"
#include "GuardMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHADOW_IA_API UGuardMovementComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TObjectPtr<AGuardPath> pathToFollow = nullptr;
	UPROPERTY(EditAnywhere) bool canMove = true;

	UPROPERTY(EditAnywhere) float patrolSpeed = 40.0f;

	FVector currentDestination;

public:	
	UGuardMovementComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Move();
	void RotateTowardDestination();
	void Init();
		
};
