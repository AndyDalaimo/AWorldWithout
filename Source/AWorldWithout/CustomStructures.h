// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomStructures.generated.h"

USTRUCT(BlueprintType)
struct FTitleGenerator : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Title)
	FString Articles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Title)
	FString Adjectives;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Title)
	FString Nouns;
};

/**
 * 
 */
class AWORLDWITHOUT_API CustomStructures
{
public:
	CustomStructures();
	~CustomStructures();
};
