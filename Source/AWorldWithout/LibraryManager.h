// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Book.h"
#include "InteractiveComputer.h"
#include "LibraryManager.generated.h"

class APuzzleDoor;

DECLARE_MULTICAST_DELEGATE_OneParam(PuzzleSignature, int);

/**
 * 
 */
UCLASS()
class AWORLDWITHOUT_API ALibraryManager : public AInfo
{
	GENERATED_BODY()

	ALibraryManager();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puzzle")
		TArray<ABook*> PuzzleBooks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puzzle")
	TArray<bool> PuzzleSolutions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puzzle")
	AInteractiveComputer* ComputerRef;

	PuzzleSignature SolutionDelegate;

	UFUNCTION(BlueprintCallable)
	void SolutionFound(int index);

protected:
	virtual void BeginPlay();

	void InitializePuzzle();
	
};
