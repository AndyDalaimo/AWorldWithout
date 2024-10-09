// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Book.h"
#include "LibraryManager.generated.h"

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
	
};
