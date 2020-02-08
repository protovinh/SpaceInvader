// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy2.generated.h"

UCLASS()
class SPACEINVADER_API AEnemy2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy2();

	UPROPERTY(EditAnywhere, Category = "Mesh")
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float Speed = 50.f;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* Collider;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
