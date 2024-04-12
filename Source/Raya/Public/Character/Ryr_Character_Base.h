// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Ryr_Character_Base.generated.h"

UCLASS(Abstract)
class RAYA_API ARyr_Character_Base : public ACharacter
{
	GENERATED_BODY()

public:

	ARyr_Character_Base();

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USkeletalMeshComponent> Mesh;



};
