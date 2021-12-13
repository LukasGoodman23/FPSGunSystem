// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Math/Rotator.h"
#include "Engine/EngineTypes.h"
#include "Sound/SoundBase.h"
#include "Particles/ParticleSystem.h"
#include "baseProjectile.h"
#include "Math/Vector.h"
#include "BaseCharacter.h"
#include "BasePerk.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "Math/UnrealMathUtility.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunBase.generated.h"

UCLASS()
class FPSGUNSYSTEM_API AGunBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunBase();

	//General Variables

	//Gun Name String
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category= "General Variables")
		FString s_gunName= FString(TEXT("gun"));

	//Hit Character Character
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "General Variables")
		class ABaseCharacter *aC_hitCharacter;

	//Kill Location Vector
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "General Variables")
		struct FVector v_killLocation= FVector(0.0, 0.0, 0.0);



	//Ammo Variables

	//Magazine Size Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Ammo Variables")
		int i_magazineSize= 0;

	//Ammo Reserve Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Ammo Variables")
		int i_ammoReserveSize= 0;

	//Current Ammo Count Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Ammo Variables")
		int i_currentAmmoCount= 0;

	//Current Ammo Reserves Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Ammo Variables")
		int i_currentAmmoReserves= 0;





	//Boolean Variables

	//Is Alternate Fire Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Boolean Variables")
		bool b_isAltFire= false;

	//Is Firing Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Boolean Variables")
		bool b_isFiring= false;

	//Is Hitscan Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Boolean Variables")
		bool b_isHitscan= true;

	//Can Recieve Input Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Boolean Variables")
		bool b_canRecieveInput= true;





	//Firing Variables

	//Fire Rate Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Variables")
		float f_firingRate= 0;

	//Bullet Distance Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Variables")
		float f_maxBulletDistance= 0;

	//Projectile First Person Projectile Class Reference
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Variables")
		TSubclassOf<class AbaseProjectile> projectile;

	//Projectile Firing Direction Rotator
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Variables")
		struct FRotator r_rotationStorage = FRotator::ZeroRotator;

	//Active Projectile First Person Projectile Object Reference
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Variables")
		class AbaseProjectile *projectileO_activeProjectile;

	//Firing Sound Sound Base Object Reference
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Variables")
		class USoundBase *soundO_firingSound;

	//MuzzleFlash Particle System Object Reference
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Variables")
		class UParticleSystem *particleO_muzzleFlash;

	//Bullet Speed Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Variables")
		float f_BulletSpeed= 0;

	//NonBulletProjectile Speed Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Variables")
		float f_nonBulletProjectileSpeed= 0;

	//Base Damage Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Variables")
		int i_baseDamage= 0;





	//Explosion Variables

	//Explosion Effect Radius Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Explosion Variables")
		float f_explosionEffectRadius= 0;

	//Explosion Appearance Radius Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Explosion Variables")
		float f_explosionAppearanceRadius= 0;

	//Explosion Max Damage Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Explosion Variables")
		int i_explosionMaxDamage= 0;

	//Explosion Appearance
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Explosion Variables")
		class UParticleSystem *partO_explosionAppearance;

	//Explosion Sound
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Explosion Variables")
		class USoundBase *soundO_explosionSound;





	//Cone Calculation Variables

	//Total Hipfire Cone Angle Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Cone Calculation Variables")
		float f_totalHipfireConeAngle= 0;

	//Total ADS Cone Angle Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Cone Calculation Variables")
		float f_totalADSConeAngle= 0;

	//Current Total Hipfire Cone Angle Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Cone Calculation Variables")
		float f_currentTotalConeAngle= 0;

	//Current Total ADS Cone Angle Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Cone Calculation Variables")
		float f_currentTotalADSConeAngle= 0;

	//Circle Projection Distance From Barrel Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Cone Calculation Variables")
		float f_circleProjectionDistanceFromBarrel= 0;

	//Inside Cone Radius Float
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category= "Firing Cone Calculation Variables")
		float f_insideConeRadius= 0;

	//Outside Cone Radius Float
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category= "Firing Cone Calculation Variables")
		float f_outsideConeRadius= 0;

	//Inside Number of Aim Wedges Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Cone Calculation Variables")
		int i_NumberOfInsideAimWedges= 0;

	//Number of Outside Aim Wedges Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Cone Calculation Variables")
		int i_NumberOfOutsideAimWedges= 7;

	//Point Angle Coordinate and Point Radius Coordinate will be Local Variables to the Function

	//Point Y Coordinate Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Cone Calculation Variables")
		float f_pointYCoordinate= 0;

	//Point Z Coordinate Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Cone Calculation Variables")
		float f_pointZCoordinate= 0;

	//Rotation on Y and Z axes will be local variables to the function

	//In Air Cone Angle Multiplier Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Cone Calculation Variables")
		float f_inAirConeAngleMultiplier= 0;

	//Number of Aim Assist Tracer Shots
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Cone Calculation Variables")
		float f_numberOfAimAssitTracerShots= 0;

	//Shot Direction Rotator Struct
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Firing Cone Calculation Variables")
		struct FRotator r_shotDirectionRotator = FRotator::ZeroRotator;





	//Falloff Calculation Variables

	//Falloff Start Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Falloff Calculation Variables")
		float f_falloffStart= 0;

	//Falloff End Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Falloff Calculation Variables")
		float f_falloffEnd= 0;

	//Shot Distance Float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Falloff Calculation Variables")
		float f_shotDistance= 0;

	//Applied Damage Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Falloff Calculation Variables")
		int i_appliedDamage= 0;





	//Gun Stats Calculation

	//Range Stat Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Falloff Calculation Variables")
		int i_range= 0;

	//Impact Stat Int
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Falloff Calculation Variables")
		int i_impact= 0;

	//Max Range Multiplier float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Falloff Calculation Variables")
		float f_maxRangeMultiplier= 0;

	//Max Impact Multiplier
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Falloff Calculation Variables")
		float f_maxImpactMultiplier= 0;




	
	//Perk Variables

	//Barrel Perk
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Perk Variables")
		TSubclassOf<class UBasePerk> BarrelPerk;

	//Magazine Perk
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Perk Variables")
		TSubclassOf<class UBasePerk> MagazinePerk;

	//Final Perk 1
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Perk Variables")
		TSubclassOf<class UBasePerk> FinalPerk1;

	//Final Perk 2
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Perk Variables")
		TSubclassOf<class UBasePerk> FinalPerk2;

	//Mod
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Perk Variables")
		TSubclassOf<class UBasePerk> Mod;





	//Components


	//Default Scene Root
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Components")
		class USceneComponent *DefaultSceneRoot;

	//Arms
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Components")
		class USkeletalMeshComponent *Arms;

	//Gun
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Components")
		class USkeletalMeshComponent *Gun;

	//Barrel Reference Point
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Components")
		class USceneComponent *BarrelReferencePoint;

	//ADS Camera
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Components")
		class UCameraComponent *ADSCamera;

	//ADS Shoot Location
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Components")
		class UArrowComponent *ADSShotLocation;

	//Shoot Location
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Components")
		class UArrowComponent *ShotLocation;





	//Functions

	//Reload
	UFUNCTION(BlueprintCallable, Category= "Gun Functions")
		virtual void reload();

	//Fire
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category= "Gun Functions")
		void fire();

	//Define On Ground Radius
	UFUNCTION(BlueprintCallable, Category= "Gun Functions")
		virtual void defineOnGroundRadius(float f_passedConeAngle);

	//Define In Air Radius
	UFUNCTION(BlueprintCallable, Category= "Gun Functions")
		virtual void defineInAirRadius(float f_passedConeAngle);
	//Rotation on Y and Z axes will be local variables to the function

	//Define Y and Z points
	UFUNCTION(BlueprintCallable, Category= "Gun Functions")
		virtual void setCartesianCoordinates(int i_currentWedgeIndex, float f_lowerRadiusBound, float f_upperRadiusBound);

	//Calculate Damage Falloff
	UFUNCTION(BlueprintCallable, Category= "Gun Functions")
		virtual void calculateDamageFalloff();

	//Define Firing Rotator
	UFUNCTION(BlueprintCallable, Category= "Gun Functions")
		virtual void setFiringRotator();





protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
