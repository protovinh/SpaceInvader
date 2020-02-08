// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy2.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
AEnemy2::AEnemy2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));		//creates a rootComponent.
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));//Enables us to set a mesh
	MeshComponent->SetupAttachment(GetRootComponent());	//sets a rootComponent
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider")); // sets the collider

}

// Called when the game starts or when spawned
void AEnemy2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

	FVector NewLocation = GetActorLocation(); // get the location of the actor
	NewLocation += GetActorForwardVector() * Speed * DeltaTime;		// moves the actor to the new location
	SetActorLocation(NewLocation);

	if (NewLocation.X < -200) {
		Destroy();
	}
}

