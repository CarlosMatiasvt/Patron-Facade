// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "PatronFacade.h"


ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{
	DefaultPawnClass = nullptr;

	// Opcional: asignar clase manualmente si no lo hacés desde el editor
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		MiClaseDePersonaje = PlayerPawnBPClass.Class;
	}
}

void ABomberMan_012025GameMode::BeginPlay()
{
	Super::BeginPlay();


	// Inicializar el nivel usando el patrón Facade
	UWorld* World = GetWorld();
	APatronFacade* Fachada = World->SpawnActor<APatronFacade>();
	Fachada->InicializarNivel(World);

	// Spawn del personaje
	SpawnPersonaje();
} 




































	/*// Creamos el director de laberinto
	UDirectorLaberinto* DirectorLaberinto = NewObject<UDirectorLaberinto>();
	// Creamos el builder concreto
	ABuilderConcretoLaberinto* BuilderLaberinto = GetWorld()->SpawnActor<ABuilderConcretoLaberinto>(ABuilderConcretoLaberinto::StaticClass());
	// Asignamos el builder al director
	DirectorLaberinto->BuilderLaberinto = BuilderLaberinto;
	// Llamamos al director para construir el laberinto
	DirectorLaberinto->contruirLaberinto();
	//Llamamos al prototipo para clonar el laberinto
	ABuilderConcretoLaberinto* ClonLaberinto = Cast<ABuilderConcretoLaberinto>(BuilderLaberinto->Clonar(GetWorld(), FVector(6000, 0, 0)));
	if (ClonLaberinto)
	{
		//verificamos que el clon se haya creado correctamente
		UE_LOG(LogTemp, Warning, TEXT("Laberinto clonado correctamente"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error al clonar el laberinto"));
	}
	// Llenamos el array de espacios vacíos y bordes
	aMapaBloques = BuilderLaberinto->aMapaBloques;
	aEspaciosVacios = BuilderLaberinto->aEspaciosVacios;
	//Spawnea el personaje xd
	SpawnPersonaje();



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
	Director2->ConstruirEjercito2(aEspaciosVacios);*/





void ABomberMan_012025GameMode::SpawnPersonaje()
{

	if (aEspaciosVacios.Num() > 0 && MiClaseDePersonaje)
	{
		int32 indiceAleatorio = FMath::RandRange(0, aEspaciosVacios.Num() - 1);
		FVector posicionInicial = aEspaciosVacios[indiceAleatorio];

		// Spawn del personaje

		FActorSpawnParameters spawnParams;
		APawn* personaje = GetWorld()->SpawnActor<APawn>(MiClaseDePersonaje, posicionInicial, FRotator::ZeroRotator, spawnParams);

		// Asignar control
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (PC && personaje)
		{
			PC->Possess(personaje);
		}
	}
}







