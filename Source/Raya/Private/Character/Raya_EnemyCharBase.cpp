// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Raya_EnemyCharBase.h"

#include "AbilitySystem/Raya_AttributeSet.h"
#include "AbilitySystem/Raya_AbilitySystemComponent.h"

/*
 * This is the base class for our enemies, currently it just calls our interface function to change some variables which means that
 * a material will activate when these functions are called.. Fuck knows where they are called..
 
 *
 * 
 */

ARaya_EnemyCharBase::ARaya_EnemyCharBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<URaya_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<URaya_AttributeSet>("AttributeSet");
	
}

void ARaya_EnemyCharBase::Highlight()
{
	bShouldHighlight = true;

	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250.f);
}

void ARaya_EnemyCharBase::UnHighlight()
{
	bShouldHighlight = false;
	GetMesh()->SetRenderCustomDepth(false);
}

void ARaya_EnemyCharBase::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this,this);
}
