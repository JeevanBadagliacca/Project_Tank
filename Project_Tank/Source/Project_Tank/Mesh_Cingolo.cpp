// Fill out your copyright notice in the Description page of Project Settings.


#include "Mesh_Cingolo.h"

UMesh_Cingolo::UMesh_Cingolo()
{
	ForzaMaxCingolo = 25000000.f;
}

void UMesh_Cingolo::RichiestaMovimento(float Movimento)
{
	if (Movimento != 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Input = %f"), Movimento);

		FVector ForzaApplicata = GetForwardVector() * ForzaMaxCingolo * Movimento; //direzione della forza

		FVector ForzaLocazione = GetComponentLocation(); //posizione del componente che applica la forza

		UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()); //Controllo se ho il component primitivo e ne ricavo il root

		if (TankRoot) 
		{
			TankRoot->AddForceAtLocation(ForzaApplicata, ForzaLocazione); //al tankroot aggiungo la forza passandogli le forze calcolate prima
		}
	
	}
}
