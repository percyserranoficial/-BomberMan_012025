// Copyright Epic Games, Inc. All Rights Reserved.

#include "SIS457_L01GameMode.h"
#include "SIS457_L01Character.h"
#include "UObject/ConstructorHelpers.h"
#include "BloqueLadrillo.h"
#include "Muro.h"

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
				FVector Location = FVector(308.0f + i * Espaciado, 1161.0f + i * EspaciadoY, 100.0f);
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

    // Contador de cuántos muros se han movido
    int32 MurosQueSeMoveran = 0;

    // Generar los muros
    for (int i = 0; i < 15; i++)
    {
        // Desviación aleatoria en el rango de -50 a 50 unidades para X y Y
        float RandomOffsetX = FMath::RandRange(-950.0f, 950.0f);
        float RandomOffsetY = FMath::RandRange(-950.0f, 950.0f);

        // Calcular la nueva ubicación basada en la última ubicación
        FVector NewLocation = BaseLocation + FVector(RandomOffsetX, RandomOffsetY, 0.0f);

        // Spawn del muro
        AMuro* NewMuro = GetWorld()->SpawnActor<AMuro>(AMuro::StaticClass(), NewLocation, Rotation);

        if (NewMuro)
        {
            // Decidir aleatoriamente si el muro se moverá
            if (MurosQueSeMoveran < 3)
            {
                // Solo los primeros 3 muros se moverán
                NewMuro->bPuedeMoverse = true;
                MurosQueSeMoveran++;  // Incrementamos el contador
            }
            else
            {
                // Los otros muros no se moverán
                NewMuro->bPuedeMoverse = false;
            }

            // Almacenar la instancia del muro (si es necesario para más operaciones)
            MurosSpawneados.Add(NewMuro);
        }
    }
}
