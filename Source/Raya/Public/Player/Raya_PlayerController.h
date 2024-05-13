// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Raya_PlayerController.generated.h"

class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

class IEnemyInterface;

/**
 * 
 */
UCLASS()
class RAYA_API ARaya_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ARaya_PlayerController();

	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;


private:


	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> MappingContext;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();

	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;


	

	
};
