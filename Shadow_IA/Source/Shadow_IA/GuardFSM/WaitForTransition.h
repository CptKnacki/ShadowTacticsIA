// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../FSM/Transition.h"
#include "WaitForTransition.generated.h"

/**
 * 
 */
UCLASS()
class SHADOW_IA_API UWaitForTransition : public UTransition
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) int waitTime = 3;
	bool isDone = false;
	FTimerHandle waitTimer;
public:
	virtual bool IsValidTransition() override;
	virtual void InitTransition(TObjectPtr<UFSM_Object> _owner) override;
	void Wait();

};
