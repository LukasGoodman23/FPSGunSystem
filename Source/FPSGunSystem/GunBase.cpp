// Fill out your copyright notice in the Description page of Project Settings.


#include "GunBase.h"

// Sets default values
AGunBase::AGunBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set Up Default Scene Root
	DefaultSceneRoot= CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Component"));
	RootComponent= DefaultSceneRoot;

	//Set Up Arms
	Arms= CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_Mannequin_Arms"));
	Arms->SetupAttachment(RootComponent);

	//Set Up Gun
	Gun= CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_FPGun"));
	Gun->SetupAttachment(Arms);

	//Set Up Barrel Reference Point
	BarrelReferencePoint= CreateDefaultSubobject<USceneComponent>(TEXT("Barrel Reference Point"));
	BarrelReferencePoint->SetupAttachment(Gun);

	//Set Up ADS Camera
	ADSCamera= CreateDefaultSubobject<UCameraComponent>(TEXT("ADS Camera"));
	ADSCamera->SetupAttachment(Gun);

	//Set Up ADS Shot Location
	ADSShotLocation= CreateDefaultSubobject<UArrowComponent>(TEXT("ADS Shot Location"));
	ADSShotLocation->SetupAttachment(ADSCamera);

	//Set Up Shot Location
	ShotLocation= CreateDefaultSubobject<UArrowComponent>(TEXT("Shot Location"));
	ShotLocation->SetupAttachment(Gun);
}

//Reload Function
void AGunBase::reload()
{
	//if there are bullets in reserve
	if (i_currentAmmoReserves > 0)
	{
		//if there are more or equal bullets in reserve than magazine size - current ammo count
		if (i_currentAmmoReserves >= (i_magazineSize - i_currentAmmoCount))
		{
			//take bullets from reserves
			i_currentAmmoReserves-= (i_magazineSize - i_currentAmmoCount);
			//fill magazine
			i_currentAmmoCount= i_magazineSize;
		}
		else
		{
			//if the bullets left in mag + all reserves are less or equal to a full mag
			if (i_currentAmmoCount + i_currentAmmoReserves <= i_magazineSize)
			{
				i_currentAmmoCount+= i_currentAmmoReserves;
				i_currentAmmoReserves= 0;
			}
			else
			{
				//take bullets from reserves
				i_currentAmmoReserves-= (i_magazineSize - i_currentAmmoCount);
				//fill magazine
				i_currentAmmoCount= i_magazineSize;
			}
		}
	}
}

//Define On Ground Radius Function
void AGunBase::defineOnGroundRadius(float f_passedConeAngle)
{
	//cut total cone angle in half to get right angle
	float f_tempConeAngle = (f_passedConeAngle / 2);

	//use tan to find max inside radius length
	f_insideConeRadius= f_circleProjectionDistanceFromBarrel * tan(FMath::DegreesToRadians(f_tempConeAngle));

	//multiply by 2 to get max outside radius length
	f_outsideConeRadius= f_insideConeRadius * 2;
}

//Define In Air Radius Function
void AGunBase::defineInAirRadius(float f_passedConeAngle)
{
	//cut total cone angle in half to get right angle
	float f_tempConeAngle= f_passedConeAngle/ 2;

	//use tan to find max radius length
	f_insideConeRadius= f_circleProjectionDistanceFromBarrel *  f_inAirConeAngleMultiplier * (tan(FMath::DegreesToRadians(f_tempConeAngle)));

	//multiply by 2 to get max outside radius length
	f_outsideConeRadius= f_outsideConeRadius * 2;
}

//Define Y and Z points
void AGunBase::setCartesianCoordinates(int i_currentWedgeIndex, float f_lowerRadiusBound, float f_upperRadiusBound)
{
	//Set random point polar coordinates

	//set point angle polar coordinate
	int i= 360/i_NumberOfInsideAimWedges;
	float f_angleAtPoint= FMath::RandRange((i*i_currentWedgeIndex), (i*(i_currentWedgeIndex+1)));

	//set point radius polar coordinate
	float f_radiusAtPoint= FMath::RandRange(FMath::FloorToInt(f_lowerRadiusBound), FMath::FloorToInt(f_upperRadiusBound));



	//Convert to Cartesian

	//Set point Y Value
	f_pointYCoordinate= cos(FMath::DegreesToRadians(f_angleAtPoint)) * f_radiusAtPoint;

	//Set point Z value
	f_pointZCoordinate= sin(FMath::DegreesToRadians(f_angleAtPoint)) * f_radiusAtPoint;
}

//Define Firing Rotator
void AGunBase::setFiringRotator()
{
	//find z axis rotation
	float f_RotationOnZAxis= FMath::RadiansToDegrees(atan2(f_pointYCoordinate, f_circleProjectionDistanceFromBarrel));

	//find new length to projection point
	float f_newCircleProjectionDistanceFromBarrel= sqrt(FMath::Square(f_pointYCoordinate) + FMath::Square(f_circleProjectionDistanceFromBarrel));

	//find y axis rotation
	float f_RotationOnYAxis= FMath::RadiansToDegrees(atan2(f_pointZCoordinate, f_newCircleProjectionDistanceFromBarrel));

	//Apply to rotator
	r_shotDirectionRotator= FRotator(f_RotationOnYAxis, f_RotationOnZAxis, 0);
}

//Calculate Damage Falloff
void AGunBase::calculateDamageFalloff()
{
	if (f_shotDistance > f_falloffEnd)
	{
		//if shot distance is past max, does no damage
		i_appliedDamage= 0;
	}
	else
	{
		if (f_shotDistance <= f_falloffStart)
		{
			//if shot distance is before falloff start do max damage
			i_appliedDamage= i_baseDamage;
		}
		else
		{
			//if shot distance is past start and before end, do damage with linear falloff
			i_appliedDamage= FGenericPlatformMath::TruncToInt(i_baseDamage * (1-((f_shotDistance-f_falloffStart)/(f_falloffEnd-f_falloffStart))));
		}
	}
}

// Called when the game starts or when spawned
void AGunBase::BeginPlay()
{
	Super::BeginPlay();

	i_currentAmmoCount= i_magazineSize;
	i_currentAmmoReserves= i_ammoReserveSize;

	f_currentTotalConeAngle= f_totalHipfireConeAngle;
	f_currentTotalADSConeAngle= f_totalADSConeAngle;
	
}

// Called every frame
void AGunBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

