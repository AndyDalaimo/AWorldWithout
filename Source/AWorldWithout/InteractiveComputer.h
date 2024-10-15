// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "Camera/CameraComponent.h"
#include "InteractiveComputer.generated.h"

class ALibraryManager;

/**
 * 
 */
UCLASS()
class AWORLDWITHOUT_API AInteractiveComputer : public AInteractableActor
{
	GENERATED_BODY()


public:

	AInteractiveComputer();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LibraryManager")
	ALibraryManager* ManagerRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* CameraComp;

	virtual void ActionToComplete_Implementation() override;

	UFUNCTION(BlueprintNativeEvent)
	void GC_ComputerInteract();
	void GC_ComputerInteract_Implementation() {};

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateSolutions(int index);
	void UpdateSolutions_Implementation(int index) {};
	
protected:

	virtual void BeginPlay() override;

};
