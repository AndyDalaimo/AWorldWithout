// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_Interactable.generated.h"

UENUM(BlueprintType)
enum class EInteractableType : uint8
{
	POSTER = 0 UMETA(DisplayName = "Poster"),
	NPC = 1 UMETA(DisplayName = "NPC"),
	BOOK = 2 UMETA(DisplayName = "Book"),
};

USTRUCT(BlueprintType)
struct FInteractData
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InteractData)
	EInteractableType InteractableType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InteractData)
	bool bSpokenTo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = InteractData)
	FString CurrentDialogue;

	// Dialogue that player will see when interacting with character for the first time
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InteractData)
	TArray<FString> FirstDialogue;

	// // Dialogue that player will see when interacting with character EVERY Subsequent interaction
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InteractData)
	TArray<FString> AfterDialogue;

	int DialogueIndex = 0;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AWORLDWITHOUT_API UAC_Interactable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_Interactable();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InteractData) 
	FInteractData InteractData;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	FString GetCurrentLineOfDialogue();
	
	UFUNCTION(BlueprintCallable)
	void SetCurrentLineOfDialogue();

};
