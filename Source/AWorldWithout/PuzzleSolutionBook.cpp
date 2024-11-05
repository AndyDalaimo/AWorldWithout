// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleSolutionBook.h"

#include "LibraryManager.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"


APuzzleSolutionBook::APuzzleSolutionBook()
{
	HintCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("HintCollision"));
	HintCollision->SetupAttachment(RootComponent);
}

void APuzzleSolutionBook::BeginPlay()
{

	Super::BeginPlay();

	ManagerRef = Cast<ALibraryManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ALibraryManager::StaticClass()));
	if (ManagerRef == nullptr) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "ManagerRef not found!");
}

// Only allow player to pick up puzzle solution book if they have recieved the hint
void APuzzleSolutionBook::ActionToComplete_Implementation()
{
	if (ManagerRef != nullptr && bHintActive)
	{
		ManagerRef->SolutionDelegate.Broadcast(SolutionIndex);
		InteractWidget->SetVisibility(false);
	}
}

void APuzzleSolutionBook::ShowInteractWidget_Implementation()
{
	if (bHintActive)
	{
		InteractWidget->SetVisibility(true);
	}
}

// Player has recieved hint and can interact with book
void APuzzleSolutionBook::HintRecieved()
{
	UE_LOG(LogTemp, Warning, TEXT("Hint Recieved at %d"), SolutionIndex);
	bHintActive = true;
}
