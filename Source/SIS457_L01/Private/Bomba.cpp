// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomba.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ABomba::ABomba()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshBomba = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBomba"));
	RootComponent = MeshBomba;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBomba(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	if (ObjetoMeshBomba.Succeeded())
	{
		MeshBomba->SetStaticMesh(ObjetoMeshBomba.Object);
	}

	MeshBomba->SetSimulatePhysics(true);

	//efecto de explosion
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ObjetoExplosion(TEXT("/Script/Engine.ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (ObjetoExplosion.Succeeded())
	{
		ExplosionEffect = ObjetoExplosion.Object;
	}

}

// Called when the game starts or when spawned
void ABomba::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(ExplocionTimer, this, &ABomba::Explotar, 20.0f, false);
}

// Called every frame
void ABomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABomba::Explotar()
{
	//radio de explosion
	float ExplosionRadio = 350.0f;

	//obtener una lista de todos los actores en el radio de la explosion
	TArray<AActor*> ActoresEnRadio;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), ActoresEnRadio);

	for (AActor* Actor : ActoresEnRadio)
	{
		if (Actor && Actor != this && !Actor->ActorHasTag("Indestructible"))
		{
			float Distancia = FVector::Dist(GetActorLocation(), Actor->GetActorLocation());
			if (Distancia <= ExplosionRadio)
			{
				Actor->Destroy();
			}
		}
	}

	if (ExplosionEffect)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
	}
	Destroy();
}

