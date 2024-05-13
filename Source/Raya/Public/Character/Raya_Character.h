// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Raya_CharacterBase.h"
#include "Raya_Character.generated.h"

class ARaya_PlayerState;
/**
 * 
 */
UCLASS()
class RAYA_API ARaya_Character : public ARaya_CharacterBase
{
	GENERATED_BODY()

public:
	ARaya_Character();

	virtual void OnRep_PlayerState() override;
	virtual void PossessedBy(AController* NewController) override;

private:
	void InitAbilityActorInfo();
	
};
