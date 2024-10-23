// Fill out your copyright notice in the Description page of Project Settings.


#include "Librarian.h"

void ALibrarian::ActionToComplete_Implementation()
{
	InteractWidget->SetVisibility(false);
	DialogueWidget->SetVisibility(true);
}



FString ALibrarian::GetCurrentDialogue()
{
	return CurrentDialogue;
}

void ALibrarian::SetCurrentDialogueInSequence()
{
	//CurrentDialogue = FirstDialogue[InteractData.DialogueIndex];
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *InteractData.CurrentDialogue);
	//if (InteractData.DialogueIndex < InteractData.FirstDialogue.Num() - 1) InteractData.DialogueIndex++;
	//else InteractData.DialogueIndex = 0;
}
