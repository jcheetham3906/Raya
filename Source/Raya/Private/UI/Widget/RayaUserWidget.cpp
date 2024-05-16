// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/RayaUserWidget.h"

void URayaUserWidget::SetWidgetController(UObject* InWidgetController)
{
	RayaWidgetController = InWidgetController;
	WidgetControllerSet();
}
