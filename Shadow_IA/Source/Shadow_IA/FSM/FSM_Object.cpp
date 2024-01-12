// Fill out your copyright notice in the Description page of Project Settings.


#include "../FSM/FSM_Object.h"
#include "FSMComponent.h"
#include "State.h"
#include <Kismet/KismetSystemLibrary.h>

void UFSM_Object::StartFSM(TObjectPtr<UFSMComponent> _owner)
{
	if (!_owner)
		return;

	fsmOwner = _owner;
	SetNextState(startingState);


}

void UFSM_Object::UpdateFSM()
{
	if (!currentState)
		return;

	currentState->Update();
}

void UFSM_Object::StopFSM()
{
	if (!currentState)
		return;

	currentState->Exit();
}

void UFSM_Object::SetNextState(TSubclassOf<UState> _nextState)
{
	if (!_nextState)
		return;

	currentState = NewObject<UState>(this, _nextState);
	currentState->Enter(this);
}
