// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "AC_Interactable.h"
#include "InteractableInterface.h"
#include "InteractableActor.generated.h"

UCLASS()
class AWORLDWITHOUT_API AInteractableActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	AInteractableActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interaction)
	UWidgetComponent* InteractWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interaction)
	UWidgetComponent* DialogueWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = Interaction)
	UAC_Interactable* InteractComp;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	// virtual void Tick(float DeltaTime) override;

	// Overridden Interface Functions (Blueprint Native Events)
	virtual void ShowInteractWidget_Implementation() override;
	virtual void HideInteractWidget_Implementation() override;
	virtual void ActionToComplete_Implementation() override;
	virtual FString GetDialogue_Implementation() override;
	virtual void SetDialogueWidget_Implementation() override;
	


};
