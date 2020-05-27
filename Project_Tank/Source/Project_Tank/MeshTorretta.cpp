// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshTorretta.h"

UMeshTorretta::UMeshTorretta()
{
	RotMaxSec = 20.f;
	RotHMaxSec = 30.f;
	ElevazioneMax = 90.f;
	ElevazioneMin = 0.f;
}

void UMeshTorretta::Eleva(float velrelativa)
{
	UE_LOG(LogTemp, Warning, TEXT("rotazione verso %f"), velrelativa);

	velrelativa = FMath::Clamp<float>(velrelativa,-1, 1);

	float CambioElevatura = velrelativa * RotMaxSec * GetWorld()->DeltaTimeSeconds;
	
	float NuovaElevatura = RelativeRotation.Pitch + CambioElevatura;

	NuovaElevatura = FMath::Clamp<float>(NuovaElevatura, ElevazioneMin, ElevazioneMax);

	SetRelativeRotation(FRotator(NuovaElevatura, 0, 0));
}

void UMeshTorretta::Ruota(float velrelativa)
{

	velrelativa = FMath::Clamp<float>(velrelativa, -1, 1);

	float CambioRotazione = velrelativa * RotHMaxSec * GetWorld()->DeltaTimeSeconds;

	float NuovaRotazione = RelativeRotation.Yaw + CambioRotazione;

	SetRelativeRotation(FRotator(0, NuovaRotazione, 0));
}