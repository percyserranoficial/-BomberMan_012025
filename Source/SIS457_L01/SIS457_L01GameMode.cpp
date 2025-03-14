// Copyright Epic Games, Inc. All Rights Reserved.

#include "SIS457_L01GameMode.h"
#include "SIS457_L01Character.h"
#include "UObject/ConstructorHelpers.h"
#include "TimerManager.h"
#include "BloqueLadrillo.h"
#include "Muro.h"
#include "Enemigps.h"
#include "BloqueAcero.h"

ASIS457_L01GameMode::ASIS457_L01GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}


}

void ASIS457_L01GameMode::BeginPlay()
{
	Super::BeginPlay();
	SpawnbloqueLadrillo();
	SpawnMuro();
    SpawnEnemigo();
	SpawnBloqueAcero();
	
}

void ASIS457_L01GameMode::SpawnbloqueLadrillo()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Bloques de ladrillo spawneados"));

	if (GEngine)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			// Número de bloques a spawnnear
			const int32 NumeroDeBloques = 10;

			// Espaciado de los bloques
			const float Espaciado = 200.0f;
			const float EspaciadoY = 100.0f;

            // Elegir un bloque aleatorio
            int32 BloqueAleatorio = FMath::RandRange(0, NumeroDeBloques - 1);

			for (int32 i = 0; i < NumeroDeBloques; ++i)
			{
				// Calcular la posición de cada bloque
				FVector Location = FVector(1308.0f + i * Espaciado, 5161.0f + i * EspaciadoY, 100.0f);
				FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);  // Rotación inicial

				// Spawnear el bloque
				//World->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), Location, Rotation);
                ABloqueLadrillo* NuevoBloque = World->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), Location, Rotation);

                if (NuevoBloque)
                {
                    // Si es el bloque aleatorio, aplica un movimiento diferente
                    if (i == BloqueAleatorio)
                    {
                        // El bloque aleatorio tendrá el movimiento hacia arriba y hacia abajo
                        NuevoBloque->MinZ = 100.0f;  // Establecer límites Z
                        NuevoBloque->MaxZ = 300.0f;
                        NuevoBloque->VelocidadMovimiento = 50.0f;  // Velocidad de movimiento
                        
                    }
                }
			}

		}
	}
}

void ASIS457_L01GameMode::SpawnMuro()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Muros spawneados"));

	// Establecer una posición base inicial para el primer muro
	FVector BaseLocation = FVector(500.0f, 2500.0f, 20.0f);
	FRotator Rotation = FRotator::ZeroRotator; // Rotación inicial

	// Array para almacenar las instancias de los muros
	TArray<AMuro*> MurosSpawneados;

	// Dimensiones del cuadrado (número de muros por lado)
	int32 MurosPorLado = 15; // Total de muros será MurosPorLado * 4
	float Separacion = 400.0f; // Distancia entre cada muro

	// Contador de cuántos muros se han movido
	int32 MurosQueSeMoveran = 0;

	// Generar los muros formando un cuadrado
	for (int i = 0; i < 4; i++) // 4 lados
	{
		for (int j = 0; j < MurosPorLado; j++)
		{
			FVector Offset(0.0f, 0.0f, 0.0f);

			switch (i)
			{
			case 0: Offset = FVector(Separacion * j, 0.0f, 0.0f); break;  // Lado superior
			case 1: Offset = FVector(Separacion * MurosPorLado, Separacion * j, 0.0f); break; // Lado derecho
			case 2: Offset = FVector(Separacion * (MurosPorLado - j), Separacion * MurosPorLado, 0.0f); break; // Lado inferior
			case 3: Offset = FVector(0.0f, Separacion * (MurosPorLado - j), 0.0f); break; // Lado izquierdo
			}

			FVector NewLocation = BaseLocation + Offset;

			// Spawn del muro
			AMuro* NewMuro = GetWorld()->SpawnActor<AMuro>(AMuro::StaticClass(), NewLocation, Rotation);

			if (NewMuro)
			{
				// Decidir aleatoriamente si el muro se moverá
				if (MurosQueSeMoveran < 3)
				{
					NewMuro->bPuedeMoverse = true;
					MurosQueSeMoveran++;  // Incrementamos el contador
				}
				else
				{
					NewMuro->bPuedeMoverse = false;
				}

				// Almacenar la instancia del muro
				MurosSpawneados.Add(NewMuro);
			}
		}
	}
}

void ASIS457_L01GameMode::SpawnEnemigo()
{
    //Spawnear 5 enemigos

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Enemigos spawneados"));

	// Establecer una posición base inicial para el primer enemigo
	FVector BaseLocation = FVector(1500.0f, 2500.0f, 20.0f);
	FRotator Rotation = FRotator::ZeroRotator; // Rotación inicial
	// Array para almacenar las instancias de los enemigos
	TArray<AEnemigps*> EnemigosSpawneados;
	// Contador de cuántos enemigos se han movido
	int32 EnemigosQueSeMoveran = 0;
	// Generar los enemigos
	for (int i = 0; i < 5; i++)
	{
		// Desviación aleatoria en el rango de -50 a 50 unidades para X y Y
		float RandomOffsetX = FMath::RandRange(-1950.0f,1950.0f);
		float RandomOffsetY = FMath::RandRange(-1950.0f, 1950.0f);
		// Calcular la nueva ubicación basada en la última ubicación
		FVector NewLocation = BaseLocation + FVector(RandomOffsetX, RandomOffsetY, 0.0f);
		// Spawn del enemigo
		AEnemigps* NewEnemigo = GetWorld()->SpawnActor<AEnemigps>(AEnemigps::StaticClass(), NewLocation, Rotation);
		if (NewEnemigo)
		{
			// Decidir aleatoriamente si el enemigo se moverá
			if (EnemigosQueSeMoveran < 3)
			{
				// Solo los primeros 3 enemigos se moverán
				NewEnemigo->bPuedeMoverse = true;
				EnemigosQueSeMoveran++;  // Incrementamos el contador
			}
			else
			{
				// Los otros enemigos no se moverán
				NewEnemigo->bPuedeMoverse = false;
			}
			// Almacenar la instancia del enemigo (si es necesario para más operaciones)
			EnemigosSpawneados.Add(NewEnemigo);
		}
	}
}

void ASIS457_L01GameMode::SpawnBloqueAcero()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Bloques de acero spawneados"));
	//en este apartado se crean las filas y columnas de los bloques de acero

	// Establecer una posición base inicial para el primer bloque de acero
	FVector BaseLocation = FVector(1500.0f, 3300.0f, 20.0f);
	FRotator Rotation = FRotator::ZeroRotator;
	int32 Filas = 17;
	int32 Columnas = 17;
	float Espaciado = 300.0f;

	UWorld* World = GetWorld();
	if (!World) return;

	for (int32 i = 0; i < Filas; ++i)
	{
		for (int32 j = 0; j < Columnas; ++j)
		{
			FVector SpawnLocation = BaseLocation + FVector(i * Espaciado, j * Espaciado, 0.0f);
			ABloqueAcero* NewEnemigo = World->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), SpawnLocation, Rotation);
		}
	}
}
