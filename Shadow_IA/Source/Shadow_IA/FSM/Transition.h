// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Transition.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class SHADOW_IA_API UTransition : public UObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TSubclassOf<class UState> nextState = nullptr;
	UPROPERTY() TObjectPtr<class UFSM_Object> owner = nullptr;

public:
	FORCEINLINE TSubclassOf<UState> GetNextState() const { return nextState; }

	virtual bool IsValidTransition();
	virtual void InitTransition(TObjectPtr<UFSM_Object> _owner);
};
