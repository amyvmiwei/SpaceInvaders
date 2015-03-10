// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceInvaders.h"
#include "BulletActor.h"


// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(this, &ABulletActor::DestroyActor, 2.0f,false);
	
}
void ABulletActor::DestroyActor()
{
	// check if actor is valid
	if (this->IsValidLowLevel())
	{
		this->Destroy();
	}
}

// Called every frame
void ABulletActor::Tick( float DeltaTime )
{
	RootComponent->MoveComponent(FVector(0.0f, 0.0f, MoveSpeed), ABulletActor::GetActorRotation(), true);
	Super::Tick( DeltaTime );

}

