// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BloqueAcero.h"
#include "BloqueEspinas.generated.h"
class UStaticMeshComponent;
/**
 * 
 */
UCLASS()
class SIS457_L01_API ABloqueEspinas : public ABloqueAcero
{
	GENERATED_BODY()
	
public:
	//constructor
	ABloqueEspinas();

	//declarando el beginplay y el tick
protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
};
