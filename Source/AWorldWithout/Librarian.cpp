// Fill out your copyright notice in the Description page of Project Settings.


#include "Librarian.h"

#include "LibraryManager.h"
#include "Kismet/GameplayStatics.h"

void ALibrarian::BeginPlay()
{
	Super::BeginPlay();

	ManagerRef = Cast<ALibraryManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ALibraryManager::StaticClass()));
	if (ManagerRef == nullptr) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "ManagerRef not found!");
}

void ALibrarian::ActionToComplete_Implementation()
{
	UpdateSeqeunce();
	SetCurrentDialogueInSequence();
	InteractWidget->SetVisibility(false);
	DialogueWidget->SetVisibility(true);
}

void ALibrarian::HideInteractWidget_Implementation()
{
	InteractWidget->SetVisibility(false);
	DialogueWidget->SetVisibility(false);
	DialogueIndex = 0;
}

FString ALibrarian::GetCurrentDialogue()
{
	return CurrentDialogue;
}

void ALibrarian::SetCurrentDialogueInSequence()
{
	if (CurrentSequence < DialogueSequencer.Num() && DialogueIndex < DialogueSequencer[CurrentSequence].Dialogue.Num())
	{
		CurrentDialogue = DialogueSequencer[CurrentSequence].Dialogue[DialogueIndex];
		UE_LOG(LogTemp, Warning, TEXT("%s"), *CurrentDialogue);
	}		

	// Increase / Reset Indices as needed
	if (DialogueIndex < DialogueSequencer[CurrentSequence].Dialogue.Num() - 1) DialogueIndex++;
	else DialogueIndex = 0;
}

// Player has found the a puzzle object, update the sequence correctly
void ALibrarian::UpdateSeqeunce()
{
	// int temp = CurrentSequence;
	CurrentSequence = ManagerRef->PuzzleSolutions.Find(false);
	UE_LOG(LogTemp, Warning, TEXT("Current Sequence: %d"), CurrentSequence);
	if (CurrentSequence == -1)
	{
		CurrentSequence = 4;
		UE_LOG(LogTemp, Warning, TEXT("All Books found, Point player towards the Door"));
	}

	if (CurrentSequence < ManagerRef->PuzzleBooks.Num())
	{
		ManagerRef->PuzzleBooks[CurrentSequence]->HintRecieved();
	}
	// temp != CurrentSequence &&
}
