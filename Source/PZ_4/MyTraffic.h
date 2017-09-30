// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTraffic.generated.h"


UCLASS()
class PZ_4_API AMyTraffic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTraffic();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* TrafficMesh;

	UPROPERTY(EditAnywhere)
	UMaterialInstanceDynamic* TrafficInstanceDyn;


	UFUNCTION()
	void Green();

	UFUNCTION()
	void Red();

	UFUNCTION()
	void Yellow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
