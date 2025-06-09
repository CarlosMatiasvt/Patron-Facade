
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BomberMan_012025GameMode.generated.h"

class ABloque;

UCLASS(minimalapi)
class ABomberMan_012025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABomberMan_012025GameMode();
public:
	void virtual BeginPlay() override;

public:
	TArray<TArray<int32>> aMapaBloques;
	TArray<FVector> aEspaciosVacios;
	TArray<FVector> aEspaciosVaciosBordes;
	TSubclassOf<APawn> MiClaseDePersonaje;
	// Declarar un array de punteros a objetos de tipo BloqueMadera
	FTimerHandle TemporizadorInicial;
	FTimerHandle tHDestruirBloques;
	TArray<ABloque*> aBloquesLadrillo;
	void SpawnPersonaje();
	//void MoverBloques();
	//void SpawnBloques();
	


};




