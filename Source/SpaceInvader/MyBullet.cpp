// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBullet.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Enemy2.h"
#include "MyPlayer.h"

// Sets default values
AMyBullet::AMyBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &AMyBullet::OnOverlap); //triggers an event in case of overlapp with other objects
	SphereCollider->SetSphereRadius(50.f); // Radius of the collider is 50.f

	RootComponent = SphereCollider; // our SphereCollider is our RootComponent

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent); //Attaches the Mesh to the RootComponent
}

// Called when the game starts or when spawned
void AMyBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector NewLocation = GetActorLocation(); // gets the current location of the actor
	NewLocation += GetActorForwardVector() * Speed * DeltaTime;		// pushes the bullet forward in this case
	SetActorLocation(NewLocation);	
}

void AMyBullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    UE_LOG(LogTemp, Warning, TEXT("Bullet Overlaps %s"), *OtherActor->GetName())

        if (OtherActor->IsA(AEnemy2::StaticClass()))
        {
            OtherActor->Destroy();

            //Alternative method to inform the enemy that it is hit
            //For instantce if the enemy has health that should be reduced
            //Cast<AEnemy>(AEnemyActor)->ImHit();

        //    //PartikkelFX: - you must the set up a ExplotionFX actor first!
        //    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplotionFX, GetTransform(), true);

        //    //SoundFX:  - you must the set up a ExplotionSound actor first!
        //    UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplotionSound, GetActorLocation());

            //Destroy Bullet:
            Destroy();
            Score += 100;
        }
}

