// Fill out your copyright notice in the Description page of Project Settings.


#include "Book.h"

// TODO ---------------------------------- TODO
// This action will Launch Book mechanic, shifting player perspective,
// opening mini-game or unique UI 
// TODO ---------------------------------- TODO
void ABook::ActionToComplete_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, TEXT("Do this instead: Book"));
	InteractWidget->SetVisibility(false);
}

void ABook::GenerateBookTitle(int32 Seed)
{
	if (DT_TitleGenerator != nullptr)
	{
		TArray<FName> RowNames = DT_TitleGenerator->GetRowNames();
		
		for (FName RowName : RowNames)
		{
			FTitleGenerator* Row = DT_TitleGenerator->FindRow<FTitleGenerator>(RowName, "");
		}
	}
}

