// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor.h"

// Sets default values
AInteractableActor::AInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComp;

	InteractWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractWidget"));
	InteractWidget->SetupAttachment(MeshComp);
	InteractWidget->SetVisibility(false);
	
	DialogueWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("DialogueWidget"));
	DialogueWidget->SetupAttachment(MeshComp);
	DialogueWidget->SetVisibility(false);

	InteractComp = CreateDefaultSubobject<UAC_Interactable>(TEXT("InteractComp"));



}

// Called when the game starts or when spawned
void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}





// Called every frame
/*void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}*/

// ---------------------------------------------------------------------
// ---------------- Overridden Interface Functions --------------------
// ---------------------------------------------------------------------
void AInteractableActor::ShowInteractWidget_Implementation(AActor* InteractableActor)
{
	// Make Widget Visible
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Show Widget"));
	InteractWidget->SetVisibility(true);
}

void AInteractableActor::HideInteractWidget_Implementation(AActor* InteractableActor)
{
	// Hide Widget
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hide Widget"));
	InteractWidget->SetVisibility(false);
	DialogueWidget->SetVisibility(false);
}

void AInteractableActor::ActionToComplete_Implementation()
{
	// UE_LOG(LogTemp, Display, TEXT("Interacting with %s"), *this->GetName());
	// InteractComp->Dialogue();
	InteractComp->SetCurrentLineOfDialogue();
	DialogueWidget->SetVisibility(true);
	
}

// Revision History 10/04/2024 - AD - Trying to not code bad ;(
// TODO ---- > Return the current line of Dialogue
FString AInteractableActor::GetDialogue_Implementation()
{
	
	return FString();
}
