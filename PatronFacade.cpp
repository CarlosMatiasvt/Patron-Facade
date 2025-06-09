// Fill out your copyright notice in the Description page of Project Settings.


#include "PatronFacade.h"
#include "BuilderConcretoLaberinto.h"
#include "DirectorLaberinto.h"
#include "DirectorEnemigo.h"
#include "PatronPrototype.h"
#include "BuilderConcretoEjercito.h"
#include "BuilderConcretoEjercito2.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APatronFacade::APatronFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APatronFacade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APatronFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void APatronFacade::InicializarNivel(UWorld* World)
{
    if (!World) return;

    CrearLaberinto(World);
    CrearEnemigos(World);
    ClonarLaberinto(World);
}

void APatronFacade::CrearLaberinto(UWorld* World)
{
    //Creamos el director de laberinto
    UDirectorLaberinto* DirectorLaberinto = NewObject<UDirectorLaberinto>();
    // Creamos el builder concreto
    ABuilderConcretoLaberinto* BuilderLaberinto = GetWorld()->SpawnActor<ABuilderConcretoLaberinto>(ABuilderConcretoLaberinto::StaticClass());
    // Asignamos el builder al director
    DirectorLaberinto->BuilderLaberinto = BuilderLaberinto;
    // Llamamos al director para construir el laberinto
    DirectorLaberinto->contruirLaberinto();
	
}

void APatronFacade::CrearEnemigos(UWorld* World)
{
	if (!World) return;
	ABuilderConcretoLaberinto* BuilderLaberinto = GetWorld()->SpawnActor<ABuilderConcretoLaberinto>(ABuilderConcretoLaberinto::StaticClass());
	TArray<TArray<int32>> aMapaBloques = BuilderLaberinto->aMapaBloques;
	TArray<FVector> aEspaciosVacios = BuilderLaberinto->aEspaciosVacios;
	FActorSpawnParameters Params;
	// Configuramos los parámetros de spawn
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	// Spawn de enemigos
	// Creamos el director de enemigos LLAMADO DIRECTOR QUE APUNTO A DIRECTORENEMIGOS
	ADirectorEnemigo* Director = GetWorld()->SpawnActor<ADirectorEnemigo>(ADirectorEnemigo::StaticClass());
	// Creamos el builder concreto ESTE BUILDER APUNTA AL BUILDERCONCRETOEJERCITO QUE NOS PERMITE SPAWNEAR A LOS ENEMIGOS
	ABuilderConcretoEjercito* Builder = GetWorld()->SpawnActor<ABuilderConcretoEjercito>(ABuilderConcretoEjercito::StaticClass());
	// Asignamos el builder al director
	//ESTE DIRECTOR APUNTA AL BUILDER QUE YA TENEMOS EN EL DIRECTORENEMIGOS LO QUE HACE ESO ES POLIMORFISMO YA QUE A ESTO LE ASIGNAMOS
	//EL NUEVO BUILDER QUE ES EL BUILDERCONCRETOEJERCITO
	// Esto es polimorfismo, el director puede usar cualquier builder que herede de ABuilderEnemigoAbstracto
	Director->Builder = Builder;
	// Llamamos al director para construir el ejército
	Director->ConstruirEjercito(aEspaciosVacios);
	// Creamos el director de enemigos 2
	ADirectorEnemigo* Director2 = GetWorld()->SpawnActor<ADirectorEnemigo>(ADirectorEnemigo::StaticClass());
	// Creamos el builder concreto 2
	ABuilderConcretoEjercito2* Builder2 = GetWorld()->SpawnActor<ABuilderConcretoEjercito2>(ABuilderConcretoEjercito2::StaticClass());
	// Asignamos el builder al director 2
	Director2->Builder = Builder2;
	// Llamamos al director 2 para construir el segundo ejército
	Director2->ConstruirEjercito2(aEspaciosVacios); 


}

void APatronFacade::ClonarLaberinto(UWorld* World)
{
	// Verificamos que el mundo no sea nulo
    TArray<AActor*> Laberintos;
    UGameplayStatics::GetAllActorsOfClass(World, ABuilderConcretoLaberinto::StaticClass(), Laberintos);

    if (Laberintos.Num() > 0)
    {
		// Verificamos que haya al menos un laberinto
        ABuilderConcretoLaberinto* Original = Cast<ABuilderConcretoLaberinto>(Laberintos[0]);
        if (Original)
        {
            Original->Clonar(World, FVector(6000, 0, 0));
        }
    }
}
