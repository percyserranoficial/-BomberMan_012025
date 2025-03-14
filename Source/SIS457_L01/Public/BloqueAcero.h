// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BloqueAcero.generated.h"
class UStaticMeshComponent;
UCLASS()
class SIS457_L01_API ABloqueAcero : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABloqueAcero();

	UStaticMeshComponent* MallaBloqueAcero;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//variables para movimiento de los bloques
	bool bMoverse;
	float VelocidadMovimiento;
	float MinZ;
	float MaxZ;
	float direccion;
};
