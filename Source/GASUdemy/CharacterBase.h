// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "CharacterBase.generated.h"


class UAttributeSetBase;


UCLASS()
class GASUDEMY_API ACharacterBase : public ACharacter , public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACharacterBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		UAbilitySystemComponent* abilitySystemComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		UAttributeSetBase* AttributeSetBaseComp;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void AquireAbility(TSubclassOf<UGameplayAbility> AblityToAquire);
};
