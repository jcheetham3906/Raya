// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Raya_PlayerState.h"

#include "AbilitySystem/Raya_AttributeSet.h"
#include "AbilitySystem/Raya_AbilitySystemComponent.h"


ARaya_PlayerState::ARaya_PlayerState()
{
	

	AbilitySystemComponent = CreateDefaultSubobject<URaya_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<URaya_AttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f;


}

UAbilitySystemComponent* ARaya_PlayerState::GetAbilitySystemComponent() const
{
	
	return AbilitySystemComponent;
	
}
