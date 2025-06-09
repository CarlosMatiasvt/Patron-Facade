// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "Kismet/KismetMathLibrary.h"
#include "AIController.h"

// Sets default values
AEnemigoBase::AEnemigoBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Configuraci�n del movimiento
	GetCharacterMovement()->MaxWalkSpeed = VelocidadMovimiento;
	// Configuraci�n de la malla
	ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin_Female.SK_Mannequin_Female'"));
	if (MeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MeshAsset.Object);
		GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
		GetMesh()->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
	}
	// Pose�do autom�ticamente por IA al colocarlo o spawnearlo
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	// Controlador por defecto
	AIControllerClass = AAIController::StaticClass();

}

// Called when the game starts or when spawned
void AEnemigoBase::BeginPlay()
{
	Super::BeginPlay();
	//timer de movimiento aleatorio
	GetWorldTimerManager().SetTimer(TimerMovimiento, this, &AEnemigoBase::MoverAleatoriamente, TiempoEntreMovimientos, true);
	
}

void AEnemigoBase::MoverAleatoriamente()
{
	// Verifica si hay posiciones libres disponibles
	if (PosicionesLibres.Num() == 0) return;
	// Selecciona un destino aleatorio
	int32 Indice = FMath::RandRange(0, PosicionesLibres.Num() - 1);
	FVector Destino = PosicionesLibres[Indice];
	// Controlador IA
	AAIController* AI = Cast<AAIController>(GetController());
	if (AI)
	{
		// Mueve al enemigo a la posici�n seleccionada
		AI->MoveToLocation(Destino);
	}
}

// Called every frame
void AEnemigoBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AEnemigoBase::SetPosicionesLibres(const TArray<FVector>& NuevasPosiciones)
{
	// Asigna las nuevas posiciones libres al enemigo
	//PosicionesLibres ya esta declarado para todo el archivo enemigo no hay necesidad de llamarlo
	PosicionesLibres = NuevasPosiciones;
}

void AEnemigoBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Llama a la implementaci�n base para configurar las entradas del jugador
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Aqu� se puede agregar mas entradas
}


