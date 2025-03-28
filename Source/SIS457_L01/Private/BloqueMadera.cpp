// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMadera.h"
#include "Components/StaticMeshComponent.h"

ABloqueMadera::ABloqueMadera()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MallaBloqueMadera = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloqueMadera"));
	RootComponent = MallaBloqueMadera;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloqueMadera(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));

	if (ObjetoMallaBloqueMadera.Succeeded())
	{
		MallaBloqueMadera->SetStaticMesh(ObjetoMallaBloqueMadera.Object);
	}

	//modificar la escala
	MallaBloqueMadera->SetWorldScale3D(FVector(2.5f, 2.5f, 2.5f));

	Tags.Add(FName("Indestructible"));
}

void ABloqueMadera::BeginPlay()
{
	Super::BeginPlay();
}

void ABloqueMadera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
