// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Raya_AttributeSet.h"

#include "Net/UnrealNetwork.h"

URaya_AttributeSet::URaya_AttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(200.f);
	
	InitMana(100.f);
	InitMaxMana(200.f);
}



void URaya_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(URaya_AttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URaya_AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URaya_AttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URaya_AttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	
}

void URaya_AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const 
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URaya_AttributeSet, Health, OldHealth);

	
}
void URaya_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const 
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URaya_AttributeSet, MaxHealth, OldMaxHealth);
}
void URaya_AttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const 
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URaya_AttributeSet, Mana, OldMana);
}
void URaya_AttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const 
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URaya_AttributeSet, MaxMana, OldMaxMana);
}
