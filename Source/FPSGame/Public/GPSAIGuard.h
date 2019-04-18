// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GPSAIGuard.generated.h"

class UPawnSensingComponent;
class APawn;

UCLASS()
class FPSGAME_API AGPSAIGuard : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGPSAIGuard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPawnSensingComponent* PawnSensingComp;

	FTimerHandle TimerHandle_ResetOrientation;

	UFUNCTION()
	void OnPawnSeen(APawn* SeenPawn);

	UFUNCTION()
	void OnNoiseHeard(APawn* NoiseInstigator, const FVector& Location, float Volume);

	FRotator OriginalRotation;
	
	UFUNCTION()
	void ResetOrientation();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
