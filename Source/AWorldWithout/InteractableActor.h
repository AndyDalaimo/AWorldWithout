// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "InteractableInterface.h"
#include "InteractableActor.generated.h"

UCLASS()
class AWORLDWITHOUT_API AInteractableActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	AInteractableActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widget)
	UWidgetComponent* InteractWidget;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	// virtual void Tick(float DeltaTime) override;

	// Overridden Interface Functions (Blueprint Native Events)
	void ShowInteractWidget_Implementation() override;
	void HideInteractWidget_Implementation() override;


};
