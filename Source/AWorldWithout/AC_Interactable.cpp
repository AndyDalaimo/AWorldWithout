// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_Interactable.h"

// Sets default values for this component's properties
UAC_Interactable::UAC_Interactable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_Interactable::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAC_Interactable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FString UAC_Interactable::GetCurrentLineOfDialogue()
{
	return InteractData.CurrentDialogue;
}

void UAC_Interactable::SetCurrentLineOfDialogue()
{	
	if (InteractData.bSpokenTo || InteractData.InteractableType == EInteractableType::POSTER)
	{
		InteractData.CurrentDialogue = InteractData.AfterDialogue[InteractData.DialogueIndex];
		UE_LOG(LogTemp, Warning, TEXT("%s"), *InteractData.CurrentDialogue);
		if (InteractData.DialogueIndex < InteractData.AfterDialogue.Num() - 1) InteractData.DialogueIndex++;
		else InteractData.DialogueIndex = 0;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *InteractData.CurrentDialogue);
		InteractData.CurrentDialogue = InteractData.FirstDialogue[InteractData.DialogueIndex];
		if (InteractData.DialogueIndex < InteractData.FirstDialogue.Num() - 1) InteractData.DialogueIndex++;
		else InteractData.DialogueIndex = 0;
	}

}

