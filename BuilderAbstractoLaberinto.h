// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuilderAbstractoLaberinto.generated.h"

class ABloque;

UCLASS()
class BOMBERMAN_012025_API ABuilderAbstractoLaberinto : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderAbstractoLaberinto();

public:
	// Declarar la posición del siguiente bloque
	FVector posicionSiguienteBloque = FVector(1000.0f, 500.0f, 20.0f);

	// Declarar un mapa de bloques como un array bidimensional
	TArray<TArray<int32>> aMapaBloques;
	ABloque* BloqueActual = nullptr;
	TArray<FVector> aEspaciosVacios;
	TArray<FVector> aEspaciosVaciosBordes;
	TArray<ABloque*> aBloques;
	float XInicial = -2500.00f;
	float YInicial = -2500.00f;
	float AnchoBloque = 100.0f;
	float LargoBloque = 100.0f;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void ConstruirLaberinto() PURE_VIRTUAL(ABuilderAbstractoLaberinto::ConstruirLaberinto, );

};
