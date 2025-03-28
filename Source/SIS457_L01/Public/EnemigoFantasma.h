// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigps.h"
#include "EnemigoFantasma.generated.h"
class UStaticMeshComponent;
/**
 * 
 */
UCLASS()
class SIS457_L01_API AEnemigoFantasma : public AEnemigps
{
	GENERATED_BODY()
	
public:
	//constructor
	AEnemigoFantasma();

	UStaticMeshComponent* MallaEnemigoFantasma;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	float AlturaMaxima = 350.0f;
	float VelocidadSalto = 800.0f;
	float AlturaInicial;
	bool bSubiendo;
};
