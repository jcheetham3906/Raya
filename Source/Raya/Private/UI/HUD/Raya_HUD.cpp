// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/Raya_HUD.h"

#include "UI/Widget/RayaUserWidget.h"

void ARaya_HUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();

	
}
