// Fill out your copyright notice in the Description page of Project Settings.

#include "BarrackActor.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
ABarrackActor::ABarrackActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SpawnPoint
	FTransform SpawnPoint;

	// Create static mesh component and set it as Root
	Mesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>("MainMesh");
	ConstructorHelpers::FObjectFinder<UStaticMesh>LoadedMesh(TEXT("StaticMesh'/Game/House/House.House'"));

	if (LoadedMesh.Object)
	{
		Mesh->SetStaticMesh(LoadedMesh.Object);
	}

	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ABarrackActor::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle Timer;

	// TEMP
	//GetWorldTimerManager().SetTimer(Timer, this, &ABarrackActor::CreateUnit, 5.0f, true);
	CreateUnit();
}

// Called every frame
void ABarrackActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Dynamically add moving objects
void ABarrackActor::CreateUnit()
{
	FVector Location(100.0f, 100.0f, 100.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	AMyCharacterUnit* Unit = GetWorld()->SpawnActor<AMyCharacterUnit>(Location, Rotation, SpawnInfo);
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, FString("Move"));
}