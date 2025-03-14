// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigps.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AEnemigps::AEnemigps()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigo"));
	RootComponent = MallaEnemigo;		

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaEnemigo(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));

	if (ObjetoMallaEnemigo.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(ObjetoMallaEnemigo.Object);	
	}

	//MallaEnemigo->SetSimulatePhysics(true);
	MallaEnemigo->SetWorldScale3D(FVector(2.5f, 2.5f, 2.5f));
}

// Called when the game starts or when spawned
void AEnemigps::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigps::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

