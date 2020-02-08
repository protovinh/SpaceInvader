// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class SPACEINVADER_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	UPROPERTY(EditAnywhere, Category = "SpawnParameters") // Editanywhere lets you edit anywhere and Category puts everyting that you put "SpawnParameters" in the same category tab.
		float SpawnLimit = 4.f;

	UPROPERTY(EditAnywhere, Category = "Spawn-parameters")
		TSubclassOf<class AEnemy2> EnemyBlueprint;    //unreal engins way to categories something like for example Damage type.

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// 1.f starts the game off with a spawn
	float LastSpawn = 1.f;

};
