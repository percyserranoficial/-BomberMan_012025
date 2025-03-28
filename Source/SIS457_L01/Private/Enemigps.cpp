// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigps.h"
#include "Components/StaticMeshComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values
AEnemigps::AEnemigps()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigo"));
	RootComponent = MallaEnemigo;		

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaEnemigo(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));

	if (ObjetoMallaEnemigo.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(ObjetoMallaEnemigo.Object);	
	}

	MallaEnemigo->SetWorldScale3D(FVector(1.5f, 1.5f, 1.5f));

	//MallaEnemigo->SetSimulatePhysics(true);


	//movimiento para enemigo
	DistanciaRecorrida = 0.0f;
}


// Called when the game starts or when spawned
void AEnemigps::BeginPlay()
{
	Super::BeginPlay();
	CambiarDireccion();
	
}

// Called every frame
void AEnemigps::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Detectar obstáculos
	FVector NuevaPosicion = GetActorLocation() + (MovimientoActual * DeltaTime * 200.0f);
	if (DetectarObstaculo(NuevaPosicion))
	{
		CambiarDireccion();
	}
	else
	{
		SetActorLocation(NuevaPosicion);
		DistanciaRecorrida += (MovimientoActual * DeltaTime * 200.0f).Size();

		if (DistanciaRecorrida >= DistanciaMaxima)
		{
			CambiarDireccion();
			DistanciaRecorrida = 0.0f;
		}
	}
}

void AEnemigps::CambiarDireccion()
{
	// Generar un vector de direccion aleatorio
	float RandomX = FMath::RandRange(-1.0f, 1.0f);
	float RandomY = FMath::RandRange(-1.0f, 1.0f);
	MovimientoActual = FVector(RandomX, RandomY, 0.0f).GetSafeNormal();
}

bool AEnemigps::DetectarObstaculo(FVector Destino)
{
	FHitResult HitResult;
	FVector Inicio = GetActorLocation();
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	//Trazar un rayo para detectar obstaculos
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Inicio, Destino, ECollisionChannel::ECC_WorldStatic, Params);

	//dibuja el rayo en el mundo para depuracion
	DrawDebugLine(GetWorld(), Inicio, Destino, FColor::Red, false, 1.0f, 0, 2.0f);

	return bHit;
}

