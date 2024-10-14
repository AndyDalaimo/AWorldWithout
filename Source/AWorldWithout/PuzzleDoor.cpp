// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleDoor.h"


// To be called in Blueprint
// Will add DoorCode UI to viewport and allow player to add code
void APuzzleDoor::ActionToComplete_Implementation()
{
	// Call to Gameplay Cue defined in BP
	// Will launch UI for DoorCode
	GC_InputDoorCode();
}

bool APuzzleDoor::CheckPasscode(int value) const
{
	if (value == Passcode)
	{
		return true;
	}
	else {
		return false;
	}
}
