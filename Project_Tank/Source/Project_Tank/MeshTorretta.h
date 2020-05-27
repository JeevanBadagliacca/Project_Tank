// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MeshTorretta.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class PROJECT_TANK_API UMeshTorretta : public UStaticMeshComponent
{
	GENERATED_BODY()
		
public:

	void Eleva(float velrelativa);

	void Ruota(float velrelativa);

	UMeshTorretta();

protected:
	
	UPROPERTY(EditAnywhere, Category="SetUp")
	float RotMaxSec;

	UPROPERTY(EditAnywhere, Category = "SetUp")
		float RotHMaxSec;

	UPROPERTY(EditAnywhere, Category="SetUp")
	float ElevazioneMax;

	UPROPERTY(EditAnywhere, Category="SetUp")
	float ElevazioneMin;
};
