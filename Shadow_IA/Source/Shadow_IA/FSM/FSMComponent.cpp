// Fill out your copyright notice in the Description page of Project Settings.


#include "../FSM/FSMComponent.h"
#include "FSM_Object.h"

UFSMComponent::UFSMComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UFSMComponent::BeginPlay()
{
	Super::BeginPlay();
	InitFSM();
	
}


void UFSMComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateFSM();
}

void UFSMComponent::InitFSM()
{
	if (!fsmToCreate)
		return;

	runningFSM = NewObject<UFSM_Object>(this, fsmToCreate);
	runningFSM->StartFSM(this);
}

void UFSMComponent::UpdateFSM()
{
	if (!runningFSM)
		return;

	runningFSM->UpdateFSM();
}

