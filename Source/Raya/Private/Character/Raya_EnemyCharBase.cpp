// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Raya_EnemyCharBase.h"

/*
 * This is the base class for our enemies, currently it just calls our interface function to change some variables which means that
 * a material will activate when these functions are called.. Fuck knows where they are called..
 
 *
 * 
 */

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
