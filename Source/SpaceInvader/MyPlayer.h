// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPlayer.generated.h"

UCLASS()
class SPACEINVADER_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Mesh")
		class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category = "Bullet")
		TSubclassOf<class AMyBullet> BulletBlueprint;  //unreal engins way to categories something like for example Damage type.

	UPROPERTY(EditAnywhere, Category = "Bullet")
		float BulletSpawnDistance = 1.f;

	UPROPERTY(EditAnywhere, Category = "PawnMovement")
	float MaxSpeed;

	UPROPERTY(EditAnywhere, Category = "FireRate")
	float SpawnLimit = 4.f;





private:

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Shoot();

	float LastSpawn = 4.f;


	FVector CurrentVelocity;
};
