// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank_C.generated.h"

UCLASS()
class PROJECT_TANK_API ATank_C : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank_C();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
		class UAiming_C* Aiming;
};
