// Fill out your copyright notice in the Description page of Project Settings.


#include "LibraryManager.h"

#include "PuzzleDoor.h"
#include "Kismet/GameplayStatics.h"

ALibraryManager::ALibraryManager()
{
}


void ALibraryManager::BeginPlay()
{
	SolutionDelegate.AddUObject(this, &ALibraryManager::SolutionFound);
	InitializePuzzle();
}

// Initialize Puzzle to Fill Solution Array with all false
// Puzzle Actors filled in before game starts
void ALibraryManager::InitializePuzzle()
{
	for (int i = 0; i < PuzzleBooks.Num(); i++)
	{
		PuzzleSolutions.Push(false);
	}
}


void ALibraryManager::SolutionFound(int index)
{
	UE_LOG(LogTemp, Display, TEXT("Soultion Found"));
	PuzzleSolutions[index] = true;

	if (PuzzleSolutions.Contains(false) == false)
	{
		UE_LOG(LogTemp, Display, TEXT("ALL Soultion Found"));
	}

}

void ALibraryManager::HintFound(int index)
{
	PuzzleBooks[index]->HintRecieved();
	UE_LOG(LogTemp, Display, TEXT("Book %d Hint Recieved"), index);
}
