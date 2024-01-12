// Fill out your copyright notice in the Description page of Project Settings.


#include "../FSM/State.h"
#include "Transition.h"
#include "FSM_Object.h"
#include <Kismet/KismetSystemLibrary.h>

void UState::Enter(TObjectPtr<UFSM_Object> _owner)
{
	owner = _owner;
	InitTransitions();

	UKismetSystemLibrary::PrintString(this, "Enter State ->" + GetName());
}

void UState::Update()
{
	CheckForValidTransitions();

}

void UState::Exit()
{

	UKismetSystemLibrary::PrintString(this, "Exit State ->" + GetName());
}

void UState::InitTransitions()
{
	for (TSubclassOf<UTransition> _transition : transitionsToCreate)
	{
		if (!_transition)
			continue;

		UTransition* _tr = NewObject<UTransition>(this, _transition);

		_tr->InitTransition(owner);
		runningTransitions.Add(_tr);
	}
}

void UState::CheckForValidTransitions()
{
	for (TObjectPtr<UTransition> _transition : runningTransitions)
	{
		if (_transition->IsValidTransition())
		{
			Exit();
			owner->SetNextState(_transition->GetNextState());
			return;
		}
	}
}