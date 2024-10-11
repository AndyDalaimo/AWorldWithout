// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "PuzzleSolutionBook.generated.h"

class ALibraryManager;

/**
 * 
 */
UCLASS()
class AWORLDWITHOUT_API APuzzleSolutionBook : public AInteractableActor
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	ALibraryManager* ManagerRef;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Solution")
	int SolutionIndex;

	// Overridden from Interactable actor 
	virtual void ActionToComplete_Implementation() override;
	
};