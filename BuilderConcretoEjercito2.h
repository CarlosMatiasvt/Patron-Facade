// Fill out your copyright notice in the Description page of Project Settings.
// BUILDERCONCRETOEJERCITO2
#pragma once

#include "CoreMinimal.h"
#include "BuilderEnemigoAbstracto.h"
#include "BuilderConcretoEjercito2.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABuilderConcretoEjercito2 : public ABuilderEnemigoAbstracto
{
	GENERATED_BODY()
public:
	// declaramos los metodos que vamos a utilizar 
	virtual void ConstruirComandante(const TArray<FVector>& PosicionesLibres) override; //override nos ayuda a sobreescribir la clase padre
	virtual void ConstruirTipo3(const TArray<FVector>& PosicionesLibres) override;
	virtual void ConstruirTipo4(const TArray<FVector>& PosicionesLibres) override;
private:
	// Funci�n auxiliar para elegir una posici�n vac�a aleatoria
	FVector ObtenerPosicionAleatoria(const TArray<FVector>& PosicionesLibres) const;

	
};
