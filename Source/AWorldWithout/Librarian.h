// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "Librarian.generated.h"

class ALibraryManager;

USTRUCT(BlueprintType)
struct FDialogueData
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	TArray<FString> Dialogue;
};

/**
 * 
 */
UCLASS()
class AWORLDWITHOUT_API ALibrarian : public AInteractableActor
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	ALibraryManager* ManagerRef;


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	int CurrentSequence;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	int DialogueIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	FString CurrentDialogue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	TArray<FDialogueData> DialogueSequencer;

	virtual void ActionToComplete_Implementation() override;

	UFUNCTION(BlueprintCallable)
	FString GetCurrentDialogue();

	UFUNCTION(BlueprintCallable)
	void SetCurrentDialogueInSequence();

	UFUNCTION(BlueprintCallable)
	void UpdateSeqeunce();

	
};
