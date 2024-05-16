// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/RayaEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/Raya_AttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
ARayaEffectActor::ARayaEffectActor()
{

	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void ARayaEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const URaya_AttributeSet* Raya_AttributeSet = Cast<URaya_AttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAttributeSet::StaticClass()));

		URaya_AttributeSet* MutableRayaAttributeSet = const_cast<URaya_AttributeSet*>(Raya_AttributeSet);

		MutableRayaAttributeSet->SetHealth(Raya_AttributeSet->GetHealth() + 25.f);
	}
	
}

void ARayaEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}


void ARayaEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ARayaEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ARayaEffectActor::EndOverlap);
	
	
}

