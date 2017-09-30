// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerActor.h"
#include "PZ_4GameMode.h"

// Sets default values
ATriggerActor::ATriggerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionMesh = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = CollisionMesh;
}

// Called when the game starts or when spawned
void ATriggerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATriggerActor::NotifyActorBeginOverlap(AActor * OtherActor)
{
	auto z = GetWorld()->GetAuthGameMode();
	Cast<APZ_4GameMode>(z)->MBegOverlab.Execute();
}

// Called every frame
void ATriggerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

