


#include "Character/Ryr_Character_Base.h"

ARyr_Character_Base::ARyr_Character_Base()
{

	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent> Mesh;
	
	

}

// Called when the game starts or when spawned
void ARyr_Character_Base::BeginPlay()
{
	Super::BeginPlay();
	
}



