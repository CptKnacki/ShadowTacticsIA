// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GuardMovementComponent.h"
#include "Guard_AI.generated.h"

UCLASS()
class SHADOW_IA_API AGuard_AI : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TObjectPtr<USkeletalMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UGuardMovementComponent> movement = nullptr;
public:
	AGuard_AI();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
