// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "State.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class SHADOW_IA_API UState : public UObject
{
	GENERATED_BODY()
	
	UPROPERTY() TObjectPtr<class UFSM_Object> owner = nullptr;
	UPROPERTY(EditAnywhere) TArray<TSubclassOf<class UTransition>> transitionsToCreate = {};
	UPROPERTY() TArray<TObjectPtr<UTransition>> runningTransitions = {};

public:
	virtual void Enter(TObjectPtr<UFSM_Object> _owner);
	virtual void Update();
	virtual void Exit();

protected:
	virtual void InitTransitions();
	virtual void CheckForValidTransitions();
};
