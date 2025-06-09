// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BuilderAbstractoLaberinto.h"
#include "DirectorLaberinto.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API UDirectorLaberinto : public UObject
{
	GENERATED_BODY()
public:
	ABuilderAbstractoLaberinto* BuilderLaberinto;
	void contruirLaberinto()
	{
		if (BuilderLaberinto)
		{
			BuilderLaberinto->ConstruirLaberinto();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("BuilderLaberinto no está asignado."));
		}
	}

};
