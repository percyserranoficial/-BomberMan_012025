// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SIS457_L01GameMode.generated.h"
class ABloqueAcero;
class ABloqueMadera;
UCLASS(minimalapi)
class ASIS457_L01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASIS457_L01GameMode();

protected:
	virtual void BeginPlay() override;

private:
	void SpawnbloqueLadrillo();
	void SpawnMuro();
	void SpawnEnemigo();
	void SpawnBloqueAcero();
	void SpawnEnemigoFantasma();
	void SpawnBomba();
	void SpawnBloqueMadera();

public:
	TArray<ABloqueAcero*> BloquesAcero;
	TArray<ABloqueMadera*> BloquesMadera;

	TArray<TArray<int32>> Laberinto1;
};



