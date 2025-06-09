// Fill out your copyright notice in the Description page of Project Settings.
// ----------- BuilderConcretoEjercito.h -----------

#pragma once

#include "CoreMinimal.h"
#include "BuilderEnemigoAbstracto.h"
#include "BuilderConcretoEjercito.generated.h"

/**
 * 
 */
 // Builder concreto que implementa los m�todos para crear el ej�rcito
UCLASS()
class BOMBERMAN_012025_API ABuilderConcretoEjercito : public ABuilderEnemigoAbstracto
{
	GENERATED_BODY()
	
public:
	// Implementaciones de los pasos del builder
	virtual void ConstruirComandante(const TArray<FVector>& PosicionesLibres) override;
	virtual void ConstruirTipo1(const TArray<FVector>& PosicionesLibres) override;
	virtual void ConstruirTipo2(const TArray<FVector>& PosicionesLibres) override;

private:
	// Funci�n auxiliar para elegir una posici�n vac�a aleatoria
	FVector ObtenerPosicionAleatoria(const TArray<FVector>& PosicionesLibres) const;
};
