// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Muro.generated.h"
class UStaticMeshComponent;
UCLASS()
class SIS457_L01_API AMuro : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMuro();

	UStaticMeshComponent* MallaMuro;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Velocidad de rotacion en yaw (en grados por segundo)
	float VelocidadRotacionYaw;
public:
	//Indica si el muro puede moverse o no
	bool bPuedeMoverse;

};
