// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemigoBase2.generated.h"

UCLASS()
class BOMBERMAN_012025_API AEnemigoBase2 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemigoBase2();


protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	float VelocidadMovimiento = 300.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	float TiempoEntreMovimientos = 3.f;

	FTimerHandle TimerMovimiento;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	TArray<FVector> PosicionesLibres;

	void MoverAleatoriamente();

public:
	virtual void Tick(float DeltaTime) override;

	void SetPosicionesLibres(const TArray<FVector>& NuevasPosiciones);

	// realiza la asignaci�n de las posiciones libres
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
