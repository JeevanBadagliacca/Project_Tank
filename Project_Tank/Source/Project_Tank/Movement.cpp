// Fill out your copyright notice in the Description page of Project Settings.


#include "Movement.h"
#include "Mesh_Cingolo.h"

UMovement::UMovement()
{

}
void UMovement::MovimentoAvanti(float MovimentoA)
{
	//UE_LOG(LogTemp, Warning, TEXT("Avanti %f"), MovimentoA);
	if (!CingoloSX || !CingoloDX)return;
	CingoloSX->RichiestaMovimento(MovimentoA);
	CingoloDX->RichiestaMovimento(MovimentoA);
}

void UMovement::MovimentoLaterale(float MovimentoL)
{
	//UE_LOG(LogTemp, Warning, TEXT("Laterale %f"), MovimentoL);
	if (!CingoloSX || !CingoloDX)return;
	CingoloSX->RichiestaMovimento(MovimentoL);
	CingoloDX->RichiestaMovimento(-MovimentoL);
}

void UMovement::SetCingoli(UMesh_Cingolo* CingoloRefSx, UMesh_Cingolo* CingoloRefDx)
{
	CingoloSX = CingoloRefSx;
	CingoloDX = CingoloRefDx;
}

void UMovement::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//Super::RequestDirectMove(MoveVelocity, bForceMaxSpeed);
	UE_LOG(LogTemp, Warning, TEXT("%s ha una velocity %s"), *GetOwner()->GetName(),*MoveVelocity.GetSafeNormal().ToString());

	FVector InAvanti = MoveVelocity.GetSafeNormal();
	FVector TankAvanti = GetOwner()->GetActorForwardVector().GetSafeNormal();
	float ProdottoScalare = FVector::DotProduct(InAvanti, TankAvanti);
	MovimentoAvanti(ProdottoScalare);


	float ProdottoVettoriale = FVector::CrossProduct(InAvanti, TankAvanti).Z;
	MovimentoLaterale(ProdottoVettoriale);
}
