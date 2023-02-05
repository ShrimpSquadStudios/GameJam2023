// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShrimpOKPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "ShrimpOKCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AShrimpOKPlayerController::AShrimpOKPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
}

void AShrimpOKPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(ShrimpMappingContext, 0);
	}
}

void AShrimpOKPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Setup move left events
		EnhancedInputComponent->BindAction(MoveLeftAction, ETriggerEvent::Started, this, &AShrimpOKPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(MoveLeftAction, ETriggerEvent::Triggered, this, &AShrimpOKPlayerController::OnTouchTriggered);
		EnhancedInputComponent->BindAction(MoveLeftAction, ETriggerEvent::Completed, this, &AShrimpOKPlayerController::OnTouchReleased);
		EnhancedInputComponent->BindAction(MoveLeftAction, ETriggerEvent::Canceled, this, &AShrimpOKPlayerController::OnTouchReleased);

		// Setup move right events
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Started, this, &AShrimpOKPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AShrimpOKPlayerController::OnTouchTriggered);
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Completed, this, &AShrimpOKPlayerController::OnTouchReleased);
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Canceled, this, &AShrimpOKPlayerController::OnTouchReleased);

		// Setup move up events
		EnhancedInputComponent->BindAction(MoveUpAction, ETriggerEvent::Started, this, &AShrimpOKPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(MoveUpAction, ETriggerEvent::Triggered, this, &AShrimpOKPlayerController::OnTouchTriggered);
		EnhancedInputComponent->BindAction(MoveUpAction, ETriggerEvent::Completed, this, &AShrimpOKPlayerController::OnTouchReleased);
		EnhancedInputComponent->BindAction(MoveUpAction, ETriggerEvent::Canceled, this, &AShrimpOKPlayerController::OnTouchReleased);

		// Setup move down events
		EnhancedInputComponent->BindAction(MoveDownAction, ETriggerEvent::Started, this, &AShrimpOKPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(MoveDownAction, ETriggerEvent::Triggered, this, &AShrimpOKPlayerController::OnTouchTriggered);
		EnhancedInputComponent->BindAction(MoveDownAction, ETriggerEvent::Completed, this, &AShrimpOKPlayerController::OnTouchReleased);
		EnhancedInputComponent->BindAction(MoveDownAction, ETriggerEvent::Canceled, this, &AShrimpOKPlayerController::OnTouchReleased);

		// Setup play note events
		EnhancedInputComponent->BindAction(PlayNoteAction, ETriggerEvent::Started, this, &AShrimpOKPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(PlayNoteAction, ETriggerEvent::Triggered, this, &AShrimpOKPlayerController::OnTouchTriggered);
		EnhancedInputComponent->BindAction(PlayNoteAction, ETriggerEvent::Completed, this, &AShrimpOKPlayerController::OnTouchReleased);
		EnhancedInputComponent->BindAction(PlayNoteAction, ETriggerEvent::Canceled, this, &AShrimpOKPlayerController::OnTouchReleased);
	}
}

void AShrimpOKPlayerController::OnInputStarted()
{
	StopMovement();
}

// Triggered every frame when the input is held down
void AShrimpOKPlayerController::OnSetDestinationTriggered()
{
	// We flag that the input is being pressed
	FollowTime += GetWorld()->GetDeltaSeconds();
	
	// We look for the location in the world where the player has pressed the input
	FHitResult Hit;
	bool bHitSuccessful = false;
	if (bIsTouch)
	{
		bHitSuccessful = GetHitResultUnderFinger(ETouchIndex::Touch1, ECollisionChannel::ECC_Visibility, true, Hit);
	}
	else
	{
		bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);
	}

	// If we hit a surface, cache the location
	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}
	
	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void AShrimpOKPlayerController::OnSetDestinationReleased()
{
	// If it was a short press
	if (FollowTime <= ShortPressThreshold)
	{
		// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}

	FollowTime = 0.f;
}

// Triggered every frame when the input is held down
void AShrimpOKPlayerController::OnTouchTriggered()
{
	bIsTouch = true;
	OnSetDestinationTriggered();
}

void AShrimpOKPlayerController::OnTouchReleased()
{
	bIsTouch = false;
	OnSetDestinationReleased();
}
