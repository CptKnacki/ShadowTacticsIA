// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FSMComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHADOW_IA_API UFSMComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TSubclassOf<class UFSM_Object> fsmToCreate = nullptr;
	UPROPERTY(VisibleAnywhere) TObjectPtr<UFSM_Object> runningFSM = nullptr;

public:	
	UFSMComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void InitFSM();
	void UpdateFSM();
		
};
