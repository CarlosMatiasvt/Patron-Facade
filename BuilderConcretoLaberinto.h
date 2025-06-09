// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuilderAbstractoLaberinto.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "PatronPrototype.h"
#include "Bloque.h"
#include "BuilderConcretoLaberinto.generated.h"
/**
* 
*/
class ABloque;
UCLASS()
class BOMBERMAN_012025_API ABuilderConcretoLaberinto : public ABuilderAbstractoLaberinto, public IPatronPrototype
{
GENERATED_BODY()
// Clase concreta que implementa el builder para construir un laberinto
// Esta clase hereda de ABuilderAbstractoLaberinto y define el método ConstruirLaberinto
private:
ABuilderConcretoLaberinto();

public:

	// Constructor
virtual void ConstruirLaberinto() override;
virtual AActor* Clonar(UWorld* World, const FVector& Offset) override;
UPROPERTY()
TArray<AActor*> Bloques;
UPROPERTY()
TArray<FVector> EspaciosVacios;
void AgregarBloque(AActor* Bloque) { Bloques.Add(Bloque); }
void AgregarEspacioVacio(const FVector& Pos) { EspaciosVacios.Add(Pos); }


};
