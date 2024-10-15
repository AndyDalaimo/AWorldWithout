// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveComputer.h"

#include "Kismet/GameplayStatics.h"
#include "LibraryManager.h"

AInteractiveComputer::AInteractiveComputer()
{
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}



void AInteractiveComputer::BeginPlay()
{
	Super::BeginPlay();

	ManagerRef = Cast<ALibraryManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ALibraryManager::StaticClass()));
	if (ManagerRef == nullptr) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "ManagerRef not found!");
}


// Will call to GameplayCue Interact
// Switch camera and allow player to interact with UI Interface
void AInteractiveComputer::ActionToComplete_Implementation()
{
	GC_ComputerInteract();
}

