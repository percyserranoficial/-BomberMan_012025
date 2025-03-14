// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueAcero.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABloqueAcero::ABloqueAcero()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MallaBloqueAcero = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloqueAcero"));
	RootComponent = MallaBloqueAcero;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloqueAcero(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	if (ObjetoMallaBloqueAcero.Succeeded())
	{
		MallaBloqueAcero->SetStaticMesh(ObjetoMallaBloqueAcero.Object);

	}

	bMoverse = FMath::RandBool();
	VelocidadMovimiento = 100.0f;
	MinZ = GetActorLocation().Z - 100.0f;
	MaxZ = GetActorLocation().Z + 100.0f;
	direccion = 1.0f;

}

// Called when the game starts or when spawned
void ABloqueAcero::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABloqueAcero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bMoverse)
	{
		FVector NuevaPosicion = GetActorLocation();
		NuevaPosicion.Z += VelocidadMovimiento * DeltaTime * direccion;

		// cambiar la direccion
		if (NuevaPosicion.Z >= MaxZ)
		{
			NuevaPosicion.Z = MaxZ;
			direccion = -1.0f;
		}
		else if (NuevaPosicion.Z <= MinZ)
		{
			NuevaPosicion.Z = MinZ;
			direccion = 1.0f;
		}

		SetActorLocation(NuevaPosicion);
	}
}

