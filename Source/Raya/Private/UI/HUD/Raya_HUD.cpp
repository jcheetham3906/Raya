// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/Raya_HUD.h"
#include "UI/WidgetController/OverlayWidgetController.h"

#include "UI/Widget/RayaUserWidget.h"

UOverlayWidgetController* ARaya_HUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		return OverlayWidgetController;
		
	}
	return OverlayWidgetController;
	
}

void ARaya_HUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	UUserWidget* Widget = CreateWidget(GetWorld(), OverlayWidgetClass);

	checkf(OverlayWidgetClass, TEXT("fuck"));
	checkf(OverlayWidgetControllerClass, TEXT("fjdfd"));

	UserWidget = Cast<URayaUserWidget>(Widget);
	
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);

	//UOverlayWidgetControllerClass*
	
	
	Widget->AddToViewport();
}

void ARaya_HUD::BeginPlay()
{
	Super::BeginPlay();



	
}
