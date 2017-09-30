// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "TriggerActor.generated.h"

UCLASS()
class PZ_4_API ATriggerActor : public AActor
{
	GENERATED_BODY()
	
	
	

public:	
	// Sets default values for this actor's properties
	ATriggerActor();

	UPROPERTY(EditAnywhere)
	UBoxComponent* CollisionMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
