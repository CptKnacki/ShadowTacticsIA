// Fill out your copyright notice in the Description page of Project Settings.


#include "../FSM/Transition.h"

bool UTransition::IsValidTransition()
{
	return false;
}

void UTransition::InitTransition(TObjectPtr<UFSM_Object> _owner)
{
	owner = _owner;
}

