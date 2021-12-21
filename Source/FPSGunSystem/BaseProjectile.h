// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

UCLASS()
class FPSGUNSYSTEM_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();





	//Variables

	//Impact Damage Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Projectile Variables")
		int i_projectileImpactDamage= 0;

	//Max Explosive Damage Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Projectile Variables")
		int i_explosionMaxDamage= 0;

	//Explosion Effect Radius Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Projectile Variables")
		float f_explosionEffectRadius= 0;

	//Explosion Appearance Radius Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Projectile Variables")
		float f_explosionAppearanceScale= 0;

	//Explosion Appearance
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Projectile Variables")
		class UParticleSystem *partO_explosionAppearance;

	//Explosion Sound
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Projectile Variables")
		class USoundBase *soundO_explosionSound;

	//Projectile Speed Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Projectile Variables")
		float f_projectileSpeed= 0;





	//Components

	//Default Scene Root
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Components")
		class USceneComponent *DefaultSceneRoot;

	//Projectile Collision
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Components")
		class USphereComponent *projectileCollision;

	//Projectile Movement Component
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Components")
		class UProjectileMovementComponent *projectileMovementComponent;





protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
