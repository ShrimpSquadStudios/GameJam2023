// Copyright (c) Shrimp Squad Studios 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "ShrimpMusicComponent.generated.h"

/**
* A position matching a specific lane that a bubble is allowed to spawn in.
*/
UENUM(BlueprintType)
enum ENotePosition
{
	Center,
	TopLeft,
	Top,
	TopRight,
	Left,
	Right,
	BottomLeft,
	Bottom,
	BottomRight,
};

/**
* Definition for a single note in a song.
*/
USTRUCT(BlueprintType)
struct FMidiNoteRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	/**
	* The time in seconds after the beginning of the song when this note should be hit by the player.
	*/
	UPROPERTY(EditAnywhere, Category = MIDI)
		float Timestamp;

	/**
	* Where the bubble corresponding to this note should spawn.
	*/
	UPROPERTY(EditAnywhere, Category = MIDI)
	TEnumAsByte<ENotePosition> Position;

	/**
	* TODO: The length of time this note should be played for.
	*/
	// UPROPERTY(EditAnywhere, Category = MIDI)
	// float Length;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHRIMPOK_API UShrimpMusicComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShrimpMusicComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
