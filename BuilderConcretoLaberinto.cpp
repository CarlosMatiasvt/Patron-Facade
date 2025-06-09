// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderConcretoLaberinto.h"
#include "Engine/Engine.h"
#include "Bloque.h"
#include "Kismet/GameplayStatics.h"
#include "BloqueAcero.h"
#include "BloqueConcreto.h"
#include "BloqueAgua.h"
#include "BloqueLadrillo.h"
#include "BloqueCesped.h"
#include "BloqueArena.h"
#include "BloqueMadera.h"
#include "BloqueRoca.h"
#include "BloqueOro.h"
#include "BloqueVidrio.h"
#include "FabricaBloques.h"

// Clase concreta que implementa el builder para construir un laberinto

ABuilderConcretoLaberinto::ABuilderConcretoLaberinto()
{
	// Inicializar el mapa de bloques
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Bloque Spawning"));
	}	// Inicializar el mapa de bloques
	aMapaBloques.SetNum(50);
	for (int32 i = 0; i < 50; i++) {
		aMapaBloques[i].SetNum(50);
	}
	//se encarga de generar aunquesea  un bloque de cada tipo
	for (int32 tipo = 1; tipo <= 9; ++tipo)
	{
		int32 fila = FMath::RandRange(1, 48);
		int32 columna = FMath::RandRange(1, 48);

		// Si ya hay un bloque distinto de 0, busca otra posición
		while (aMapaBloques[fila][columna] != 0)
		{
			fila = FMath::RandRange(1, 48);
			columna = FMath::RandRange(1, 48);
		}

		aMapaBloques[fila][columna] = tipo;
	}
	//generamos los demas bloques
	for (int32 i = 1; i <= 180; ++i)
	{

		int32 fila = FMath::RandRange(1, 48);
		int32 columna = FMath::RandRange(1, 48);
		int32 tipo = FMath::RandRange(1, 9); // Genera un número aleatorio entre 1 y 10

		// Si ya hay un bloque distinto de 0, busca otra posición
		while (aMapaBloques[fila][columna] != 0)
		{
			fila = FMath::RandRange(1, 48);
			columna = FMath::RandRange(1, 48);
		}

		aMapaBloques[fila][columna] = tipo;
	}
}

void ABuilderConcretoLaberinto::ConstruirLaberinto()
{
	//fabrica de bloques
	UFabricaBloques* Fabrica = NewObject<UFabricaBloques>();
	// Recorremos la matriz para generar los bloques
	for (int32 fila = 0; fila < aMapaBloques.Num(); ++fila)
	{
		for (int32 columna = 0; columna < aMapaBloques[fila].Num(); ++columna)
		{

			int32 valor = aMapaBloques[fila][columna];
			// Calculamos la posición del bloque

			FVector posicionBloque = FVector(
				XInicial + columna * AnchoBloque,
				YInicial + fila * LargoBloque,
				20.0f); // Z (altura del bloque)

			if (valor == 0) // Si es espacio vacío
			{
				if (fila == 0 || fila == 49 || columna == 0 || columna == 49) {
					//spawnear los limited con acero
					ABloque* NuevoBloque = Fabrica->CrearBloque(GetWorld(), 0, posicionBloque);
					if (NuevoBloque)
					{
						AgregarBloque(NuevoBloque); // ? ¡Esto es esencial!

					}
				}
				else {
					// Añadir la posición a los espacios vacíos
					aEspaciosVacios.Add(posicionBloque);
					AgregarEspacioVacio(posicionBloque); // ? ¡Esto es esencial!
					

				}
			}
			else {
				// Spawn del bloque usando la fábrica
				ABloque* NuevoBloque = Fabrica->CrearBloque(GetWorld(), valor, posicionBloque);     
				if (NuevoBloque)
				{
					AgregarBloque(NuevoBloque); // ? ¡Esto es esencial!

				}

			}
		}
	}
}
// Clona el laberinto actual y lo posiciona en un nuevo mundo con un desplazamiento dado
AActor* ABuilderConcretoLaberinto::Clonar(UWorld* World, const FVector& Offset)
{
	if (!World) return nullptr;
	// Verifica que el mundo no sea nulo
	FActorSpawnParameters Params;
	// Configura los parámetros de spawn
	
	ABuilderConcretoLaberinto* Clon = World->SpawnActor<ABuilderConcretoLaberinto>(GetClass(), GetActorLocation() + Offset, GetActorRotation(), Params);

	if (!Clon)
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR: No se pudo clonar el laberinto"));
		return nullptr;
	}
	// Clonamos los bloques y espacios vacíos
	for (AActor* Bloque : Bloques)
	{
		if (!Bloque) continue;
		// Verifica que el bloque no sea nulo
		// Calcula la nueva posición del bloque clonado
		FVector NuevaPos = Bloque->GetActorLocation() + Offset;
		TSubclassOf<AActor> Clase = Bloque->GetClass();
		AActor* BloqueClonado = World->SpawnActor<AActor>(Clase, NuevaPos, FRotator::ZeroRotator, Params);

		Clon->AgregarBloque(BloqueClonado);
	}

	for (const FVector& Pos : EspaciosVacios)
	{
		// Verifica que la posición no sea nula
		Clon->AgregarEspacioVacio(Pos + Offset);
	}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Clonando laberinto..."));
	}
	// Log de depuración para verificar que el clon se ha creado correctamente
	return Clon;
}