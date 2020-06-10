// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank_C.h"
#include "Aiming_C.h"
#include "MeshTorretta.h"
#include "Proiettile.h"
#include "Engine/World.h"

// Sets default values
ATank_C::ATank_C()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Aiming = CreateDefaultSubobject<UAiming_C>(TEXT("Aiming"));
	ReloadTime = 2.f;
}

// Called when the game starts or when spawned
void ATank_C::BeginPlay()
{
	Super::BeginPlay();

	Reload = 0;
}

// Called every frame
void ATank_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Reload > 0) Reload -= DeltaTime;
}

// Called to bind functionality to input
void ATank_C::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank_C::Spara()
{
	if (Projectile1 && GetWorld() && Reload<=0)
	{
		//UE_LOG(LogTemp, Error, TEXT("Sparo a salve"));

		auto Bullet = GetWorld()->SpawnActor<AProiettile>(Projectile1,
			Cannone->GetSocketLocation(FName("Proiettile")),
			Cannone->GetSocketRotation(FName("Proiettile"))
			);
		Bullet->Lancio(Aiming->VelLancio);

		Reload = ReloadTime;
	}
}

void ATank_C::AimAt(FVector HitLocation)
{
	Aiming->AimAt(HitLocation);
	//UE_LOG(LogTemp, Warning, TEXT("Il Tank %s mira a:%s "), *GetName(), *HitLocation.ToString());
}

void ATank_C::SetCannone(UMeshTorretta* CannonRef)
{
	Cannone = CannonRef;
}


