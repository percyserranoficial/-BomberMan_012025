// Fill out your copyright notice in the Description page of Project Settings.


#include "Muro.h"
#include "Components/StaticMeshComponent.h"
#include "Math/UnrealMathUtility.h"	

// Sets default values
AMuro::AMuro()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MallaMuro = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaMuro"));
	RootComponent = MallaMuro;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaMuro(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));	

	if (ObjetoMallaMuro.Succeeded())
	{
		MallaMuro->SetStaticMesh(ObjetoMallaMuro.Object);

		//MallaMuro->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	VelocidadRotacionYaw = 30.0f; // 50 grados por segundo

	//Decidir aleatoriamente si el muro puede moverse o no
	bPuedeMoverse = FMath::RandBool();

	//modificar la escala de Muro
	MallaMuro->SetWorldScale3D(FVector(2.5f, 2.5f, 8.5f));

	//fisicas para el muro
	MallaMuro->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void AMuro::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//si el muro puede moverse, aplicamos la rotacion
	if (bPuedeMoverse)
	{
		//obetener la rotacion actual
		FRotator RotacionActual = GetActorRotation();

		//Incrementar la Rotacion en Yaw
		RotacionActual.Yaw += VelocidadRotacionYaw * DeltaTime;

		//Establecer la nueva rotacion
		SetActorRotation(RotacionActual);

	}
}

