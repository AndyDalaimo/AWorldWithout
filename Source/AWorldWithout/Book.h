// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomStructures.h"
#include "InteractableActor.h"
#include "Book.generated.h"



/**
 * 
 */
UCLASS()
class AWORLDWITHOUT_API ABook : public AInteractableActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Title)
	FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Title)
	UDataTable* DT_TitleGenerator;

	// Overridden from Interactable actor 
	virtual void ActionToComplete_Implementation() override;

	UFUNCTION(BlueprintCallable)
	void GenerateBookTitle(int32 Seed);
	
};
