
#include "Character/Raya_CharacterBase.h"

/*
 * In the base character constructor it's an abstract class
 * It's only purpose is to have features that are usefull for both enemies and playable characters
 * it is abstract meaning it will never be instantiated
 * Perhaps it says abstract in the header file?
 *
 * it can't ever tick (as it wont ever be directly added to the game? but how does that work with inheritence?
 *
 * We've created a USkeletalMeshComponent Variable and asigned the result of the method 'CreateDefaultSubobject'
 * Then we call the method setup attatchment to attatch it to a socket
 * and we also set it to have no collision
 *
 * then we override BeginPlay and just call super...
 */
ARaya_CharacterBase::ARaya_CharacterBase()
{

	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	
	
}

UAbilitySystemComponent* ARaya_CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void ARaya_CharacterBase::BeginPlay()
{
	Super::BeginPlay();

	
	
}



