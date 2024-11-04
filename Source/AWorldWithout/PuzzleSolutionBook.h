// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "PuzzleSolutionBook.generated.h"

class ALibraryManager;
class UBoxComponent;

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

	APuzzleSolutionBook();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hint")
	UBoxComponent* HintCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Title)
	FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hint")
	bool bHintActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Solution")
	int SolutionIndex;

	// Overridden from Interactable actor 
	virtual void ActionToComplete_Implementation() override;
	virtual void ShowInteractWidget_Implementation() override;
	
	// Hint in world found, trigger Dynamic Material
	UFUNCTION(BlueprintCallable)
	void HintRecieved();
};
