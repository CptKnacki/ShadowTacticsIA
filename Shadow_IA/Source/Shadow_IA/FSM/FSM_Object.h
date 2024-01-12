// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FSM_Object.generated.h"

/**
 * 
 */

class UState;

UCLASS(Abstract, Blueprintable)
class SHADOW_IA_API UFSM_Object : public UObject
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere) TSubclassOf<UState> startingState = nullptr;
	UPROPERTY() TObjectPtr<UState> currentState = nullptr;

	UPROPERTY() TObjectPtr<class UFSMComponent> fsmOwner = nullptr;

public:
	virtual void StartFSM(TObjectPtr<UFSMComponent> _owner);
	virtual void UpdateFSM();
	virtual void StopFSM();

	void SetNextState(TSubclassOf<UState> _nextState);
};
