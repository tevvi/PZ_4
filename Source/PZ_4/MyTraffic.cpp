// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTraffic.h"
#include "PZ_4GameMode.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
AMyTraffic::AMyTraffic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TrafficMesh = CreateDefaultSubobject<UStaticMeshComponent>("TrafficMesh");

	ConstructorHelpers::FObjectFinder<UStaticMesh> loadedMesh(TEXT("StaticMesh'/Game/ExampleContent/NetworkFeatures/Meshes/SM_Traffic_Light.SM_Traffic_Light'"));
	
	if (loadedMesh.Object)
		TrafficMesh->SetStaticMesh(loadedMesh.Object);
	
	RootComponent = TrafficMesh;
	TrafficInstanceDyn = TrafficMesh->CreateAndSetMaterialInstanceDynamic(1);
	TrafficInstanceDyn->SetScalarParameterValue(TEXT("State"),0);
}

void AMyTraffic::Green()
{
	TrafficInstanceDyn->SetScalarParameterValue(TEXT("State"), 0);
	auto cworld = GetWorld()->GetAuthGameMode();
	auto mgamemode = Cast<APZ_4GameMode>(cworld);
	mgamemode->ActorVisibility.ExecuteIfBound(false);
}

void AMyTraffic::Red()
{
	TrafficInstanceDyn->SetScalarParameterValue(TEXT("State"), 1);
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AMyTraffic::Yellow, 3);
	auto cworld = GetWorld()->GetAuthGameMode();
	auto mgamemode = Cast<APZ_4GameMode>(cworld);
	mgamemode->ActorVisibility.ExecuteIfBound(true);
	
}

void AMyTraffic::Yellow()
{
	TrafficInstanceDyn->SetScalarParameterValue(TEXT("State"), 0.5);
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AMyTraffic::Green, 3);
	
}

// Called when the game starts or when spawned
void AMyTraffic::BeginPlay()
{
	Super::BeginPlay();
	auto z = Cast<APZ_4GameMode>(GetWorld()->GetAuthGameMode());
	z->MBegOverlab.BindDynamic(this, &AMyTraffic::Red);
}



// Called every frame
void AMyTraffic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

