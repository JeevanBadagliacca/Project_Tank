// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank_AIC.h"
#include "Tank_C.h"
#include "Tank_PC.h"
#include "Engine/World.h"


ATank_AIC::ATank_AIC()
{
    Timer = FMath::FRandRange(3.f, 6.f);
    RaggioMax = 3000.f;
}

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

void ATank_AIC::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    auto Bersaglio = GetPlayerTank();

    if (Bersaglio)
    {
        GetTank()->AimAt(Bersaglio->GetActorLocation());
        if (Timer > 0) Timer -= DeltaTime;
        else 
        {
            //GetTank()->Spara();
            Timer = FMath::FRandRange(3.f, 6.f);
        }

       auto path = MoveToActor(Bersaglio, RaggioMax);
       UE_LOG(LogTemp, Warning, TEXT("path =%i"), path);
    }
}

ATank_C* ATank_AIC::GetTank() const
{
    return Cast<ATank_C>(GetPawn());
}