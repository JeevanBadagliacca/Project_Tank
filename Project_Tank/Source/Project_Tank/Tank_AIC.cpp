// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank_AIC.h"
#include "Tank_C.h"
#include "Tank_PC.h"
#include "Engine/World.h"

ATank_C* ATank_AIC::GetPlayerTank() const
{
    auto controller= GetWorld()->GetFirstPlayerController();

    return Cast<ATank_C>(controller->GetPawn());
}

void ATank_AIC::BeginPlay()
{
    Super::BeginPlay();

    auto CarroControllato = GetPawn();
    auto CarroNemico = GetPlayerTank();

    if (!CarroControllato || !CarroNemico) return;

    if (CarroControllato)
    {
        UE_LOG(LogTemp, Warning, TEXT("Trovato %s"), *CarroControllato->GetName()); //mettiamo l'asterisco perchè si sta usando una stringa
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Trovato %s"),*GetName());
    }
}

ATank_C* ATank_AIC::GetTank() const
{
    return Cast<ATank_C>(GetPawn());
}