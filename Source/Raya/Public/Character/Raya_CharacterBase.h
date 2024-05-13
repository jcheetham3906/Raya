
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Raya_CharacterBase.generated.h"

UCLASS()
class RAYA_API ARaya_CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	ARaya_CharacterBase();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;


};
