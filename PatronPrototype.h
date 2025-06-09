// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PatronPrototype.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPatronPrototype : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMAN_012025_API IPatronPrototype
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Clona el laberinto actual y lo posiciona en un nuevo mundo con un desplazamiento dado
	// Esta funci�n debe ser implementada por las clases que hereden de este prototipo
	virtual AActor* Clonar(UWorld* World, const FVector& Offset) = 0;
};
