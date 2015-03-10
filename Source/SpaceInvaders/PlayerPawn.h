// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class SPACEINVADERS_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void MoveSideways(float value);
	
	UPROPERTY(Category = Gameplay, EditDefaultsOnly, BlueprintReadWrite)
		float MoveSpeed = 1;

	UPROPERTY(Category = Gameplay, EditDefaultsOnly, BlueprintReadWrite)
		float BulletGap = 1;

	void Shoot();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Gameplay)
		UClass* MyBulletBlueprint;

	template <typename ASpawnBP>
	FORCEINLINE ASpawnBP* SpawnBP(
		UWorld* TheWorld,
		UClass* TheBP,
		const FVector& Loc,
		const FRotator& Rot,
		const bool bNoCollisionFail = true,
		AActor* Owner = NULL,
		APawn* Instigator = NULL
		)
	{
		if (!TheWorld) return NULL;
		if (!TheBP) return NULL;
		//~~~~~~~~~~~

		FActorSpawnParameters SpawnInfo;
		SpawnInfo.bNoCollisionFail = bNoCollisionFail;
		SpawnInfo.Owner = Owner;
		SpawnInfo.Instigator = Instigator;
		SpawnInfo.bDeferConstruction = false;

		return TheWorld->SpawnActor<ASpawnBP>(TheBP, Loc, Rot, SpawnInfo);
	}

	
};
