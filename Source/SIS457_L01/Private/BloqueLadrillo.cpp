// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueLadrillo.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABloqueLadrillo::ABloqueLadrillo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//declarando la malla
	MallaBloque = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloque"));
	//RootComponent = MeshBloque;
	MallaBloque->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloque(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	if (ObjetoMallaBloque.Succeeded())
	{
		MallaBloque->SetStaticMesh(ObjetoMallaBloque.Object);

		MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	//MallaBloque->SetSimulatePhysics(true);

	MovimientoVelocidad = FVector(100.0f, 0.0f, 0.0f); // movimiento a la derecha
}

// Called when the game starts or when spawned
void ABloqueLadrillo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABloqueLadrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NuevaUbicacion = GetActorLocation() + (MovimientoVelocidad * DeltaTime);
	SetActorLocation(NuevaUbicacion); //mueve el bloque

	//Obtener la posicion actila del bloque
	FVector CurrentLocation = GetActorLocation();

	//Mover el bloque en el eje Z
	CurrentLocation.Z += VelocidadMovimiento * DeltaTime * DireccionZ;

	//si el bloque llega al limite superior o inferior, cambiar la direccion
	if (CurrentLocation.Z >= MaxZ || CurrentLocation.Z <= MinZ)
	{
		DireccionZ *= -1;
	}

	//Actualizar la posicion del bloque
	SetActorLocation(CurrentLocation);
}
