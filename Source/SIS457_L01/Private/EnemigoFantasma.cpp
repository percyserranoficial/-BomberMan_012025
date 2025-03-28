// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoFantasma.h"
#include "Components/StaticMeshComponent.h"

AEnemigoFantasma::AEnemigoFantasma()
{
	PrimaryActorTick.bCanEverTick = true;

	MallaEnemigoFantasma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigoFantasma"));
	RootComponent = MallaEnemigoFantasma;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaEnemigoFantasma(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));

	if (ObjetoMallaEnemigoFantasma.Succeeded())
	{
		MallaEnemigoFantasma->SetStaticMesh(ObjetoMallaEnemigoFantasma.Object);
	}
}

void AEnemigoFantasma::BeginPlay()
{
	Super::BeginPlay();
	AlturaInicial = GetActorLocation().Z;
}

void AEnemigoFantasma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NuevaPosicion = GetActorLocation();

	//logica de salto continuo
	if (bSubiendo)
	{
		NuevaPosicion.Z += VelocidadSalto * DeltaTime;

		//si alcanzaAltursMaxima, cambia la direccion
		if (NuevaPosicion.Z >= AlturaInicial + AlturaMaxima)
		{
			NuevaPosicion.Z = AlturaInicial + AlturaMaxima;
			bSubiendo = false;
		}
	}
	else
	{
		NuevaPosicion.Z -= VelocidadSalto * DeltaTime;

		//si alcanza la altura inicial, cambia la direccion
		if (NuevaPosicion.Z <= AlturaInicial)
		{
			NuevaPosicion.Z = AlturaInicial;
			bSubiendo = true;
		}
	}
	SetActorLocation(NuevaPosicion);
}
