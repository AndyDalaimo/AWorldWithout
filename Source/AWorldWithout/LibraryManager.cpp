// Fill out your copyright notice in the Description page of Project Settings.


#include "LibraryManager.h"

ALibraryManager::ALibraryManager()
{
}


void ALibraryManager::BeginPlay()
{
	SolutionDelegate.AddUObject(this, &ALibraryManager::SolutionFound);
	InitializePuzzle();
}

// Initialize Puzzle to Fill Solution Array with all false
void ALibraryManager::InitializePuzzle()
{
	for (int i = 0; i < 4; i++)
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