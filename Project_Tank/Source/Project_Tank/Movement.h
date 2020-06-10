// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "Movement.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class PROJECT_TANK_API UMovement : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	class UMesh_Cingolo* CingoloSX;
	class UMesh_Cingolo* CingoloDX;

	UMovement();

	UFUNCTION(BlueprintCallable, Category = "Controlli")
	void MovimentoAvanti(float MovimentoA);

	UFUNCTION(BlueprintCallable, Category = "Controlli")
	void MovimentoLaterale(float MovimentoL);

	UFUNCTION(BlueprintCallable, Category = "Controlli")
	void SetCingoli(UMesh_Cingolo* CingoloRefSx, UMesh_Cingolo* CingoloRefDx);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
};

