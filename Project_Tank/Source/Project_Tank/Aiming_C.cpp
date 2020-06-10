// Fill out your copyright notice in the Description page of Project Settings.


#include "Aiming_C.h"
#include "Tank_C.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "MeshTorretta.h"

// Sets default values for this component's properties
UAiming_C::UAiming_C()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	VelLancio = 100000.f;
}


// Called when the game starts
void UAiming_C::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAiming_C::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAiming_C::AimAt(FVector HitLocation)
{
	//UE_LOG(LogTemp, Warning, TEXT("Porca Troia 2 "));
	if (!Cannone)return;
	FVector Velocity;
	FVector StartLocation = Cannone->GetSocketLocation(FName("Proiettile"));
	FCollisionResponseParams ResponseParam;
	TArray < AActor* > Ignore;

	//UE_LOG(LogTemp, Warning, TEXT("Porca Troia "));

	bool results = UGameplayStatics::SuggestProjectileVelocity
	(
		this,                  //l'oggetto che esegue       
		Velocity,              //passata per riferimento direzione da calcolare
		StartLocation,        
		HitLocation,
		VelLancio,            //forza di lancio
		false,                //arco alto si o no
		0,                    //eventuale raggio di collisione
		0,                    //sovrascrivi gravità 
		ESuggestProjVelocityTraceOption::DoNotTrace       //parametri del trace 
		//ResponseParam,                                  //risposta del trace
		//Ignore,                                         //ignorati dal trace
		//true                                            //linea di debug
	);

	if (results)
	{
		RuotaCannone(Velocity);
	}

	
}

void UAiming_C::RuotaCannone(FVector& Velocity)
{
	FVector AimDirection = Velocity.GetSafeNormal();  //Get Safe Normal  trasforma il vettore in vettore normalizzato

	//UE_LOG(LogTemp, Warning, TEXT("Angolazione %s "), *AimDirection.ToString());

	FRotator RotAttuale = Cannone->GetForwardVector().Rotation();

	FRotator RotObiettivo = AimDirection.Rotation();

	FRotator DeltaRot = RotObiettivo - RotAttuale;

	Cannone->Eleva(DeltaRot.Pitch);

	if (FMath::Abs(DeltaRot.Yaw) < 180)
	{
		Torretta->Ruota(DeltaRot.Yaw);
	}
	else 
	{
		Torretta->Ruota(-DeltaRot.Yaw);
	}


}

void UAiming_C::SetCannone(UMeshTorretta* CannoneRef)
{
	Cannone = CannoneRef;
}

void UAiming_C::SetTorretta(UMeshTorretta* TorreRef)
{
	Torretta = TorreRef;
}

