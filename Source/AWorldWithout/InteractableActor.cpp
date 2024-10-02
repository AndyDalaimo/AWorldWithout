// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor.h"

// Sets default values
AInteractableActor::AInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	InteractWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractWidget"));
	InteractWidget->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	InteractWidget->SetVisibility(false);


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
void AInteractableActor::ShowInteractWidget_Implementation()
{
	// Make Widget Visible
	InteractWidget->SetVisibility(true);
}

void AInteractableActor::HideInteractWidget_Implementation()
{
	// Hide Widget
	InteractWidget->SetVisibility(false);
}