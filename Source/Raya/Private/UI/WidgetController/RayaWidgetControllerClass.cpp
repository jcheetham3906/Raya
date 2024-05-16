// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/RayaWidgetControllerClass.h"

void URayaWidgetControllerClass::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	AttributeSet = WCParams.AttributeSet;
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
}
