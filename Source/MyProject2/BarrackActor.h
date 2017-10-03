// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrackUnit.h"
#include "MyCharacterUnit.h"
#include "BarrackActor.generated.h"

UCLASS()
class MYPROJECT2_API ABarrackActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrackActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UFUNCTION()
	void CreateUnit();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
