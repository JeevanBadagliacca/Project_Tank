// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank_PC.h"
#include "Tank_C.h"
#include "Camera/PlayerCameraManager.h"
#include "Engine/World.h"

void ATank_PC::BeginPlay()
{
    Super::BeginPlay();

    auto CarroControllato = GetPawn();
    

    if (CarroControllato)
    {
        UE_LOG(LogTemp, Warning, TEXT("Trovato %s"), *CarroControllato->GetName()); //mettiamo l'asterisco perchè si sta usando una stringa
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Trovato %s"));
    }
}

void ATank_PC::Mira()
{
    if (!GetTank()) return;

    FVector HitLocation;

    if (TrovaVista(HitLocation))
    {
        UE_LOG(LogTemp, Warning, TEXT("ZonaMirata %s"), *HitLocation.ToString());
    }
}

bool ATank_PC::TrovaVista(FVector& Location)
{
    //------------------------------------------------------------------------------------------
    // individuare la zona mirata
    int32 ViewX, ViewY;

    GetViewportSize(ViewX, ViewY);
    FVector2D AimView = FVector2D(ViewX * 0.5, ViewY * 0.3);
    
    FVector Direzione;
    TrovaDirezione(AimView, Direzione);

    FVector HitLocation;
    TrovaHit(Direzione, HitLocation);

    return true;
}

bool ATank_PC::TrovaDirezione(FVector2D ScreenLocation, FVector& Direzione)
{
    //------------------------------------------------------------------------------------------
    // convertire la zona da 2d a 3d

    FVector WorldLocation;

    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, Direzione);
}

bool ATank_PC::TrovaHit(FVector Direzione, FVector& HitLocation)
{
    //------------------------------------------------------------------------------------------
   // creare un linetrace

    auto StartLocation = PlayerCameraManager->GetCameraLocation();

    FHitResult Hit;

    FVector EndLine = StartLocation + (Direzione * LineTraceRange);

    if(GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, EndLine,ECollisionChannel::ECC_Visibility))
    {
        HitLocation = Hit.Location;
        return true;
    }
    HitLocation = FVector(0, 0, 0);
    return false;
}

void ATank_PC::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    Mira();
}

ATank_PC::ATank_PC()
{
    LineTraceRange = 100000.f;
}

ATank_C* ATank_PC::GetTank() const
{
    return Cast<ATank_C>(GetPawn());
 }
