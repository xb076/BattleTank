// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming_Component"));

}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	if (TankAimingComponent) TankAimingComponent->SetBarrelReference(BarrelToSet);
	if (BarrelToSet) Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	if (TankAimingComponent) TankAimingComponent->SetTurretReference(TurretToSet);
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *(GetName()), *(HitLocation.ToString()));
}

void ATank::Fire()
{
	bool isReload = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReload && Barrel && ProjectileBlueprint) {

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		if (Projectile) Projectile->LaunchProjectile(LaunchSpeed);
	
		LastFireTime = FPlatformTime::Seconds();
	}

	
}





