// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleSolutionBook.h"

#include "LibraryManager.h"
#include "Kismet/GameplayStatics.h"


void APuzzleSolutionBook::BeginPlay()
{
	ManagerRef = Cast<ALibraryManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ALibraryManager::StaticClass()));
	if (ManagerRef == nullptr) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "ManagerRef not found!");
}

void APuzzleSolutionBook::ActionToComplete_Implementation()
{
	if (ManagerRef != nullptr)
	{
		ManagerRef->SolutionDelegate.Broadcast(SolutionIndex);
	}
}
