// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Raya_CharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "Raya_EnemyCharBase.generated.h"

/**
 * 
 */
UCLASS()
class RAYA_API ARaya_EnemyCharBase : public ARaya_CharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:

	virtual void Highlight() override;
	virtual void UnHighlight() override;

	UPROPERTY(BlueprintReadOnly)
	bool bShouldHighlight = false;
	
};
