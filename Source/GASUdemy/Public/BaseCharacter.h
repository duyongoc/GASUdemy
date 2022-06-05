// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"

#include "BaseCharacter.generated.h"

class UBaseAttributeSet;

UCLASS()
class GASUDEMY_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseCharacter")
		UAbilitySystemComponent* AbilitySystemComp;

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		void InitalizeAbility(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel);

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseCharacter")
		const class UBaseAttributeSet* BaseAttributeSetComp;

	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
		void GetHealthValues(float& Health, float& MaxHealth);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
		void GetManaValues(float& Mana, float& MaxMana);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
		void GetStaminaValues(float& Stamina, float& MaxStamina);

	void OnHealthChangeNative(const FOnAttributeChangeData& Data);
	void OnManaChangeNative(const FOnAttributeChangeData& Data);
	void OnStaminaChangeNative(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
		void OnHealthChaged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
		void OnManaChaged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
		void OnStaminaChaged(float OldValue, float NewValue);

};
