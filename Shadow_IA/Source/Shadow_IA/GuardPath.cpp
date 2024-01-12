// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardPath.h"

// Sets default values
AGuardPath::AGuardPath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGuardPath::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGuardPath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();
}

void AGuardPath::DrawDebug()
{
	if (checkpoints.Num() > 2)
	{
		for (size_t i = 0; i < checkpoints.Num(); i++)
		{
			if (!checkpoints[i])
				continue;

			if (i == checkpoints.Num() - 1)
			{
				if (!checkpoints[0])
					continue;
				DrawDebugLine(GetWorld(), checkpoints[i]->GetActorLocation(), checkpoints[0]->GetActorLocation(), FColor::Red, false, -1, 0, 2.0f);
			}
			else
			{
				if (!checkpoints[i + 1])
					continue;
				DrawDebugLine(GetWorld(), checkpoints[i]->GetActorLocation(), checkpoints[i + 1]->GetActorLocation(), FColor::Red, false, -1, 0, 2.0f);
			}
		}
	}
}

FVector AGuardPath::GetNextCheckpoint(FVector _currentCheckpoint)
{
	for (size_t i = 0; i < checkpoints.Num(); i++)
	{
		if (!checkpoints[i])
			continue;

		if (checkpoints[i]->GetActorLocation() == _currentCheckpoint)
		{
			if (i == checkpoints.Num() - 1)
				return checkpoints[0]->GetActorLocation();
			else
				return checkpoints[i + 1]->GetActorLocation();
		}
	}

	return FVector(0);
}

bool AGuardPath::ShouldTickIfViewportsOnly() const
{
	return true;
}

