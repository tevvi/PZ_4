// Fill out your copyright notice in the Description page of Project Settings.

#include "Obstacle.h"
#include "PZ_4GameMode.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TrigMesh = CreateDefaultSubobject<UStaticMeshComponent>("TrigMesh");

	ConstructorHelpers::FObjectFinder<UStaticMesh> loadedCube(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (loadedCube.Object)
		TrigMesh->SetStaticMesh(loadedCube.Object);
	RootComponent = TrigMesh;
	
}

void AObstacle::SetMeshVisibility(bool f)
{
	TrigMesh->SetVisibility(f);
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	TrigMesh->SetVisibility(false);
	auto cworld = GetWorld()->GetAuthGameMode();
	auto mgamemode = Cast<APZ_4GameMode>(cworld);
	mgamemode->ActorVisibility.BindUObject(this, &AObstacle::SetMeshVisibility);
}


// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

