// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "PuzzleDoor.generated.h"

/**
 * 
 */
UCLASS()
class AWORLDWITHOUT_API APuzzleDoor : public AInteractableActor
{
	GENERATED_BODY()

public:
	// Overridden from Interactable actor 
	virtual void ActionToComplete_Implementation() override;

	UFUNCTION(BlueprintNativeEvent)
	void GC_InputDoorCode();
	void GC_InputDoorCode_Implementation() {};
	
};