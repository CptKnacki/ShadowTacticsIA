// Fill out your copyright notice in the Description page of Project Settings.


#include "../GuardFSM/WaitForTransition.h"

bool UWaitForTransition::IsValidTransition()
{
	return isDone;
}

void UWaitForTransition::InitTransition(TObjectPtr<UFSM_Object> _owner)
{
	Super::InitTransition(_owner);
	GetWorld()->GetTimerManager().SetTimer(waitTimer,this, &UWaitForTransition::Wait, waitTime, false);

}

void UWaitForTransition::Wait()
{
	isDone = true;
}
