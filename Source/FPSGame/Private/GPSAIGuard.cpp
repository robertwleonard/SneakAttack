// Fill out your copyright notice in the Description page of Project Settings.

#include "GPSAIGuard.h"
#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"


// Sets default values
AGPSAIGuard::AGPSAIGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->OnSeePawn.AddDynamic(this, &AGPSAIGuard::OnPawnSeen);
}

// Called when the game starts or when spawned
void AGPSAIGuard::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGPSAIGuard::OnPawnSeen(APawn* SeenPawn)
{
	if (!SeenPawn)
	{
		return;
	}

	DrawDebugSphere(GetWorld(), SeenPawn->GetActorLocation(), 32.0f, 12, FColor::Green, false, 10.0f);
}

// Called every frame
void AGPSAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

