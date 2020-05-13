// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank_PC.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_TANK_API ATank_PC : public APlayerController
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere)
	float LineTraceRange;

public:

	ATank_PC();

	class ATank_C* GetTank() const;  //class per non avere l'errore, gli include sono ricorsivi, di solito se ne lasciano minimi neel'header e si usa class
	                                //il nome di questa tecnica è Forward Delclaration 

	virtual void BeginPlay()override;

	void Mira();

	bool TrovaVista(FVector& Location);

	bool TrovaDirezione(FVector2D ScreenLocation, FVector& Direzione);

	bool TrovaHit(FVector Direzione, FVector& HitLocation);


	virtual void Tick(float DeltaTime)override;
};
