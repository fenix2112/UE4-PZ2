// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacterUnit.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
AMyCharacterUnit::AMyCharacterUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	MeshView = CreateOptionalDefaultSubobject<UStaticMeshComponent>("MainMesh");
	ConstructorHelpers::FObjectFinder<UStaticMesh>LoadedMesh(TEXT("StaticMesh'/Game/Unit/bb8.bb8'"));

	if (LoadedMesh.Object)
	{
		MeshView->SetStaticMesh(LoadedMesh.Object);
	}
	
	RootComponent = MeshView;


}

// Called when the game starts or when spawned
void AMyCharacterUnit::BeginPlay()
{
	Super::BeginPlay();
    NavSys = GetWorld()->GetNavigationSystem();

	if (NavSys )
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, FString("NavSys"));

		NavSys->SimpleMoveToLocation(this->GetController(), FVector(300.0f,300.0f,300.0f));
	}

	AddMovementInput(FVector(10.0f, 0.0f, 0.0f), 5.0f);

}

// Called every frame
void AMyCharacterUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
	
	//FVector forward = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraRotation().Vector();

	

	
}

// Called to bind functionality to input
void AMyCharacterUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

