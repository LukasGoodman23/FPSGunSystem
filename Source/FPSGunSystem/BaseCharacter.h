// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class FPSGUNSYSTEM_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	//health Bool
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Base Character")
		int i_health= 100;

	//isDead Bool
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category= "Base Character")
		bool b_isDead= false;

	//canAffectHealth Bool
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category= "Base Character")
		bool b_canAffectHealth= true;

	//Amount of slow int
	UPROPERTY(BLueprintReadWrite, EditAnywhere, Category= "Base Character")
		int i_slowAmount= 0;

	//Amount of slow int
	UPROPERTY(BLueprintReadWrite, EditAnywhere, Category= "Base Character")
		bool b_isFrozen= false;





	//Functions

	//isDead helper function
	virtual void calculateDead();

	//blueprint function
	UFUNCTION(BlueprintCallable, Category = "Base Character")
		virtual void calculateHealth(int i_MinusDamage);

	//canAffectHealth helper function
	virtual void calculateCanAffectHealth();

	//Suppress function
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category= "Character Effects")
		void suppress();

	//Burn function
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category= "Character Effects")
		void burn(int i_numTicks, int i_burnDamage);

	//Arc Web function
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category= "Character Effects")
		void arcWeb(int i_arcDamage);

	//Slow function
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category= "Character Effects")
		void slow(int i_amountOfSlowApplied);

	//Freeze function
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category= "Character Effects")
		void freeze();






	//editor only code
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent &PropertyChangedEvent) override;
#endif //WITH_EDITOR

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
