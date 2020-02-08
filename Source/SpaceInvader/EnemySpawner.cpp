// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Enemy2.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Adding time to the LastSpawn
	LastSpawn += DeltaTime;

	if (SpawnLimit < LastSpawn)
	{
		UWorld* World = GetWorld(); // Get the game world
		if (World)
		{
			World->SpawnActor<AEnemy2>(EnemyBlueprint, GetActorLocation(), GetActorRotation()); //Spawns the Enemy
		}

		//resets the LastSpawn time so that it can spawn again
		LastSpawn = 0.f;
	}
}

