// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RayaUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class RAYA_API URayaUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> RayaWidgetController;

protected:
	
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UUserWidget> RayaUserWidget;
	
};
