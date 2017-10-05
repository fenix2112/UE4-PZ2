// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AI/Navigation/NavigationSystem.h"
#include "MyCharacterUnit.generated.h"

UCLASS()
class MYPROJECT2_API AMyCharacterUnit : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterUnit();


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* MeshView;

	UPROPERTY()
	UCharacterMovementComponent* test;

	/*UPROPERTY()
	UNavigationSystem* NavSys;*/

	UPROPERTY()
	UCharacterMovementComponent* Movement;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
