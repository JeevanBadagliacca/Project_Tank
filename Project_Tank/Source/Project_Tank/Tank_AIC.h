// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank_AIC.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_TANK_API ATank_AIC : public AAIController
{
	GENERATED_BODY()


		float Timer;

public:

	ATank_AIC();

	class ATank_C* GetTank() const;  //class per non avere l'errore, gli include sono ricorsivi, di solito se ne lasciano minimi neel'header e si usa class
									//il nome di questa tecnica è Forward Delclaration 

	class ATank_C* GetPlayerTank() const;

	virtual void BeginPlay()override;

	virtual void Tick(float DeltaTime) override;
};
