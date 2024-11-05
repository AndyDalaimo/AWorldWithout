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
void ALibraryManager::InitializePuzzle()
{
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APuzzleSolutionBook::StaticClass(), Actors);
	for (int i = 0; i < Actors.Num(); i++)
	{
		PuzzleBooks.Push(Cast<APuzzleSolutionBook>(Actors[i]));
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
