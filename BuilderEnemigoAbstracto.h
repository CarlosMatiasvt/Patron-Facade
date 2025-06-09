// Fill out your copyright notice in the Description page of Project Settings.
// ----------- BuilderEnemigoAbstracto.h -----------
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuilderEnemigoAbstracto.generated.h"

// Clase abstracta del Builder, define los metodos que se utilizaran
//de aqui salen todos los metodos que usaran las clases hijas
//se hereda de Actor porque es un objeto que se coloca en el mundo del juego
UCLASS()
class BOMBERMAN_012025_API ABuilderEnemigoAbstracto : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderEnemigoAbstracto();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//declaracion de todos los metodos
public:
	// Métodos virtual puro: deben ser implementados por clases hijas
	virtual void ConstruirComandante(const TArray<FVector>& PosicionesLibres) PURE_VIRTUAL(ABuilderEnemigoAbstracto::ConstruirComandante,) ;
	// Construir enemigos de tipo 1, 2, 3 y 4
	// Estos métodos son opcionales, pueden ser implementados o no por las clases hijas
	// ya que si hacemos estos metodos puros deberiamos hacer todas estas funciones a cada builder que deseemos hacer
	//lo que es lo contrario de agilizar
	virtual void ConstruirTipo1(const TArray<FVector>& PosicionesLibres)  {}; 
	virtual void ConstruirTipo2(const TArray<FVector>& PosicionesLibres)  {};
	virtual void ConstruirTipo3(const TArray<FVector>& PosicionesLibres)  {};
	virtual void ConstruirTipo4(const TArray<FVector>& PosicionesLibres)  {};

};
