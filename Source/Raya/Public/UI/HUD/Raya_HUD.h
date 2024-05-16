// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Raya_HUD.generated.h"

class URayaUserWidget;
/**
 * 
 */
UCLASS()
class RAYA_API ARaya_HUD : public AHUD
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<URayaUserWidget> UserWidget;

protected:
	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<URayaUserWidget> OverlayWidgetClass;
};
