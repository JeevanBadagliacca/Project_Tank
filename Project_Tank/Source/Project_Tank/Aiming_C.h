// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Aiming_C.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_TANK_API UAiming_C : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAiming_C();

	UPROPERTY(EditAnywhere, Category = "Fuoco")
		float VelLancio;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	class UMeshTorretta* Cannone;

	class UMeshTorretta* Torretta;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation);

	void RuotaCannone(FVector& Velocity);

	FORCEINLINE UMeshTorretta* GetCannone() { return Cannone; }

	UFUNCTION(BlueprintCallable)
	void SetCannone(UMeshTorretta*CannoneRef);

	FORCEINLINE UMeshTorretta* GetTorretta() { return Torretta; }

	UFUNCTION(BlueprintCallable)
		void SetTorretta(UMeshTorretta* TorreRef);

};
