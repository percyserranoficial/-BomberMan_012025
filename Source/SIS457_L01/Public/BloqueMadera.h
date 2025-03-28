// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BloqueAcero.h"
#include "BloqueMadera.generated.h"
class UStaticMeshComponent;
/**
 * 
 */
UCLASS()
class SIS457_L01_API ABloqueMadera : public ABloqueAcero
{
	GENERATED_BODY()
	
public:
	ABloqueMadera();

	UStaticMeshComponent* MallaBloqueMadera;

//declarando el beginplay y el tick
protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

};
