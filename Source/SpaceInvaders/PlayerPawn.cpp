// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceInvaders.h"
#include "PlayerPawn.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void APlayerPawn::MoveSideways(float value)
{
	if (FMath::Abs(value) > 0.0f)
	{
		FRotator ActorRotation = APlayerPawn::GetActorRotation();
		FVector Movement = ActorRotation.RotateVector(FVector(-value, 0.0f, 0.0f)) * MoveSpeed;
		RootComponent->MoveComponent(Movement, ActorRotation, true);
	}
}

void APlayerPawn::Shoot()
{
	if (CanFire)
	{
		const FVector  GenSpawnLoc(0.0f, 0.0f, 0.0f);
		const FRotator GenSpawnRot(0.0f, 0.0f, 0.0f);
		SpawnBP<AActor>(GetWorld(), MyBulletBlueprint, APlayerPawn::GetActorLocation(), GenSpawnRot);
		CanFire = false;
		GetWorldTimerManager().SetTimer(this, &APlayerPawn::AllowFiring, 0.7f, false);
	}

}
void APlayerPawn::AllowFiring()
{
	CanFire = true;
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	InputComponent->BindAxis("MoveSideWays", this, &APlayerPawn::MoveSideways);
	InputComponent->BindAction("Shoot", IE_Pressed, this, &APlayerPawn::Shoot);
	Super::SetupPlayerInputComponent(InputComponent);

}

