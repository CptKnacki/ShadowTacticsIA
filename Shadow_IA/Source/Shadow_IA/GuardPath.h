// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GuardPath.generated.h"

UCLASS()
class SHADOW_IA_API AGuardPath : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TArray<AActor*> checkpoints = {};

	
public:	
	AGuardPath();
	FORCEINLINE TArray<AActor*> GetCheckpoints() const { return checkpoints; }
	FVector GetNextCheckpoint(FVector _currentCheckpoint);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual bool ShouldTickIfViewportsOnly() const override;
	void DrawDebug();

};
