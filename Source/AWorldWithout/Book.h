// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	// Overridden from Interactable actor 
	virtual void ActionToComplete_Implementation() override;
	
};
