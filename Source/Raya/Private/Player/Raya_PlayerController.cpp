// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Raya_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

class UEnhancedInputComponent;

/*
 * This is the most complex class..
 * Firstly we enable bReplicates to true.. This is so the player controller can be replicated in case of making this a
 * multiplayer game.. I guess this is so in multiplayer other machines can see that WASD etc has been pressed?
 *
 * Then we have over ridden PlayerTick, called super and called our function CursorTrace (more info on that below
 */

ARaya_PlayerController::ARaya_PlayerController()
{
	bReplicates = true;
	
}

void ARaya_PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

/*
 * So.. CursorTrace is a function we are calling everyframe in PlayerTick
 *
 * Firstly we are creating a local Struct of type FHitResult
 * Then we use a method which is available in the PlayerController class called GetHitResultUnderCursor
 *
 * In this method we have do pass in a trace channel, whether or not we want to trace complex and then a variable to store the
 * return value of the method.. which in this case is a FHitResult
 *
 * We then check if our struct's bBlockingHit variable is true (IE was anything detected).. If nothing was hit we just return and need
 * no further checks
 *
 * But if we continue then something was hit..
 *
 * So next we set LastActor to ThisActor (this is kind of both null at the start..
 * But the next line we check to see if the thing we hit has an IEnemyInterface.. If it does then the actor is stored
 * in ThisActor.. If it doesn't then ThisActor stores a nullptr
 *
 * Then we do some logic to work out whether or not to call our highlight and unhighlight functions on our LastActor/ThisActor variables
 *
 * It looks complex.. but really it's just highlighting or unhighligting depending on whether it's already highlighted or not..
 * 
 */

void ARaya_PlayerController::CursorTrace()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

	if (!HitResult.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(HitResult.GetActor());

	if (LastActor == nullptr)
	{
		if(ThisActor != nullptr)
		{
			ThisActor->Highlight();
		}
		else
		{
			// Do nothing
		}
	}
	if (LastActor != nullptr)
	{
		if (ThisActor == nullptr)
		{
			LastActor->UnHighlight();
		}
		else
		{
			//Do Nothing
		}
	}
	if ( LastActor != nullptr && ThisActor != nullptr)
	{
		if (LastActor == ThisActor) return;

		if (LastActor != ThisActor)
		{
			LastActor->UnHighlight();
			ThisActor->Highlight();
		}
			
	

		
	}

	
}


/*
 * OOff this class is a bit of a beast..
 *
 * So.. It seems Beginplay is where we setup our localplayersubsystem
 *
 * We get the subsystem from ULocalPlayer class and then we AddMappingContext, passing in our variable which we set in BP
 *
 * Then we setup the Struct FInputModeGameAndUI and showmousecursor.. THen we use the method SetInputMode, passing in our struct.
 *
 * 
 * 
 */

void ARaya_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);

	Subsystem->AddMappingContext(MappingContext, 0);

	bShowMouseCursor = true;
	FInputModeGameAndUI InputModeGameAndUI;
	InputModeGameAndUI.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeGameAndUI.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeGameAndUI);
	
}

/*
 * Still not fully understanding this..
 *
 * But essentially we are casting 'InputComponent' to an EnhancedInputComponent and then calling BindAction, passing in our Input Action
 * and binding our Move function to it..
 */

void ARaya_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARaya_PlayerController::Move);
	
	
}

/*
 * Here we firstly store the value from the FInputActionValue???
 *
 * Which somehow is the value of the input action?
 *
 * We get it as a vector 2d..
 * then we get the control rotation
 * then we get a normalised vector using FRotationMatric
 *
 * We check if theres a controlled pawn and store it in a local variable
 *
 * If there is a controlled pawn then we add MovementInput passing in a vector and  value to scale it by..
 *
 * This class definitely needs some more work to fully understand it.. FUCK.
 * 
 */
void ARaya_PlayerController::Move(const FInputActionValue& Value)
{


	const FVector2D AxisVector = Value.Get<FVector2D>();
	const FRotator Rotator = GetControlRotation();
	const FRotator YawRotation(0.f, Rotator.Yaw, 0.f);

	FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* controlledPawn = GetPawn())
	{
		controlledPawn->AddMovementInput(Forward, AxisVector.Y);
		controlledPawn->AddMovementInput(Right, AxisVector.X);
		
	}
	
	
	
	
}


