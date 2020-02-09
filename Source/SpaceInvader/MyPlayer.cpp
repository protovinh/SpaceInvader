// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "MyBullet.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());



	CurrentVelocity = FVector(0.f);
	MaxSpeed = 100.f;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	Score = 0;
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LastSpawn += DeltaTime;


	FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
	
	if (NewLocation.Y < 820 && NewLocation.Y > -820) {
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	//PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyPlayer::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyPlayer::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &AMyPlayer::Shoot);

}

//void AMyPlayer::MoveForward(float Value)
//{
//	CurrentVelocity.X = FMath::Clamp(Value, -1.f, 1.f) * MaxSpeed;
//
//}
void AMyPlayer::MoveRight(float Value)
{
	//the velocity in which the object moves in the Y axis
	CurrentVelocity.Y = FMath::Clamp(Value, -1.f, 1.f) * MaxSpeed;

}

void AMyPlayer::Shoot()
{
	if (SpawnLimit < LastSpawn) {

		UWorld* World = GetWorld();
		if (World)
		{
			World->SpawnActor<AMyBullet>(BulletBlueprint, GetActorLocation() + FVector(BulletSpawnDistance, 0.f, 0.f), GetActorRotation());
		}
		LastSpawn = 0.f;
	}
}
