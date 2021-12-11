// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseProjectile.h"

// Sets default values
ABaseProjectile::ABaseProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set Up Default Scene Root
	DefaultSceneRoot= CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Component"));
	RootComponent= DefaultSceneRoot;

	//Set Up Collision Component
	projectileCollision= CreateDefaultSubobject<USphereComponent>(TEXT("Projectile Collision Component"));
	projectileCollision->SetupAttachment(RootComponent);

	//Set Up Mesh
	projectileMesh= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Arms"));
	projectileMesh->SetupAttachment(RootComponent);

	//Set Up Movement Component
	projectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	projectileMovementComponent->SetUpdatedComponent(DefaultSceneRoot);
}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

