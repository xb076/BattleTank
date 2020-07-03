// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"


class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	ATank* GetControlledTank() const;
	
	ATank* GetPlayerTank() const;
	
};
