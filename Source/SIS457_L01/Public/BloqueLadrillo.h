// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BloqueLadrillo.generated.h"
class UStaticMeshComponent;
UCLASS()
class SIS457_L01_API ABloqueLadrillo : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABloqueLadrillo();

	UStaticMeshComponent* MallaBloque;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector MovimientoVelocidad;
public:
	//Rango de movimiento en el eje Z
	float MinZ = 100;
	float MaxZ = 200;

	//Velocidad del movimiento
	float VelocidadMovimiento = 100.0f;

	//direccion del movimiento (1 o -1)

	int DireccionZ = 1;
};
