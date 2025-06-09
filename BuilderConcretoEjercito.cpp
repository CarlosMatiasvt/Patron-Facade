// Fill out your copyright notice in the Description page of Project Settings.

// ----------- BuilderConcretoEjercito.cpp -----------

#include "BuilderConcretoEjercito.h"
#include "EnemigoTipo1.h"
#include "EnemigoTipo2.h"
#include "EnemigoComandante.h"
#include "Kismet/GameplayStatics.h" //esto es una libreria que nos permite usar SpawnActor


void ABuilderConcretoEjercito::ConstruirComandante(const TArray<FVector>& PosicionesLibres)
{
	// Spawnea el comandante en una posici�n aleatoria
	FVector Pos = ObtenerPosicionAleatoria(PosicionesLibres);
	FActorSpawnParameters Params;
	// auto significa que el compilador deduce el tipo de la variable
	auto Comandante = GetWorld()->SpawnActor<AEnemigoComandante>(AEnemigoComandante::StaticClass(), Pos, FRotator::ZeroRotator, Params);
	if (Comandante)
		Comandante->SetPosicionesLibres(PosicionesLibres);
}

void ABuilderConcretoEjercito::ConstruirTipo1(const TArray<FVector>& PosicionesLibres)
{
	//Spawnea un enemigo tipo 1 en una posici�n aleatoria
	FVector Pos = ObtenerPosicionAleatoria(PosicionesLibres);
	FActorSpawnParameters Params;
	// auto significa que el compilador deduce el tipo de la variable
	auto Tipo1 = GetWorld()->SpawnActor<AEnemigoTipo1>(AEnemigoTipo1::StaticClass(), Pos, FRotator::ZeroRotator, Params);
	if (Tipo1)
		//manda las posiciones libres al enemigo tipo 2
		Tipo1->SetPosicionesLibres(PosicionesLibres);
}

void ABuilderConcretoEjercito::ConstruirTipo2(const TArray<FVector>& PosicionesLibres)
{
	//Spawnea un enemigo tipo 2 en una posici�n aleatoria
	FVector Pos = ObtenerPosicionAleatoria(PosicionesLibres);
	//Crea los par�metros de spawn
	FActorSpawnParameters Params; //esto nos sirve cuando queremos spawnear una estructura con spawnactor
	// Spawnea el enemigo tipo 2
	// auto significa que el compilador deduce el tipo de la variable
	auto Tipo2 = GetWorld()->SpawnActor<AEnemigoTipo2>(AEnemigoTipo2::StaticClass(), Pos, FRotator::ZeroRotator, Params);
	if (Tipo2)
		//manda las posiciones libres al enemigo tipo 2
		Tipo2->SetPosicionesLibres(PosicionesLibres);
}

FVector ABuilderConcretoEjercito::ObtenerPosicionAleatoria(const TArray<FVector>& PosicionesLibres) const
{
	// Verifica si hay posiciones libres disponibles
		// Devuelve una posici�n vac�a aleatoria del mapa
	if (PosicionesLibres.Num() == 0) return FVector::ZeroVector;
	int32 Indice = FMath::RandRange(0, PosicionesLibres.Num() - 1);
	return PosicionesLibres[Indice];
}