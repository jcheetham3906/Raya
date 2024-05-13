// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Raya_Character.h"
#include "GameFramework/CharacterMovementComponent.h"

/*
 * This is the constructor for Raya Character class
 * In it we are Getting access to the character movement component so that we can set some variables that effects how the character moves
 * bOrientRotationToMovement means that the character will always face the way they are moving
 * snap to plane at start is self explanatory
 * rotation rate is self explanatory
 * constrain to plane is often used in top down games to constrain the movement to a plane..
 *
 * The use controller pitch/yaw/roll is so its not influenced by the controllers rotation.. I'll have to check
 * what happens if i switch that off..
 */
ARaya_Character::ARaya_Character()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f,0.f);
	GetCharacterMovement()->bConstrainToPlane = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;



	
}

