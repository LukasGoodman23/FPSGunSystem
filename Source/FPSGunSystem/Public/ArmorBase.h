// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ArmorBase.generated.h"


//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

UCLASS(Blueprintable, BlueprintType)
class FPSGUNSYSTEM_API UArmorBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UArmorBase();

	//Mods

	//Stat Mod
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Perk Variables")
		TSubclassOf<class UBasePerk> statMod;

	//Armor Mod 1
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Perk Variables")
		TSubclassOf<class UBasePerk> armorMod1;

	//Armor Mod 2
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Perk Variables")
		TSubclassOf<class UBasePerk> armorMod2;

	//Combat Style Mod
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Perk Variables")
		TSubclassOf<class UBasePerk> combatStyleMod;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Function to be Called on Component Construction
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category= "Armor Functions")
		void onConstruction();

	//Called on Player Melee Ability Activation
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category= "Armor Functions")
		void onMelee();

	//Called on Player Grenade Ability Activation
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category= "Armor Functions")
		void onGrenade();
		
};
