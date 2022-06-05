// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "BaseAttributeSet.h"


ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComp)
	{
		BaseAttributeSetComp = AbilitySystemComp->GetSet<UBaseAttributeSet>();

		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetHealthAttribute()).AddUObject(this, &ABaseCharacter::OnHealthChangeNative);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetManaAttribute()).AddUObject(this, &ABaseCharacter::OnManaChangeNative);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetStaminaAttribute()).AddUObject(this, &ABaseCharacter::OnStaminaChangeNative);
	}
}

void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::InitalizeAbility(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel)
{
	if (AbilitySystemComp)
	{
		if (HasAuthority() && AbilityToGet)
		{
			AbilitySystemComp->GiveAbility(FGameplayAbilitySpec(AbilityToGet, AbilityLevel, 0));
		}
		AbilitySystemComp->InitAbilityActorInfo(this, this);
	}
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

void ABaseCharacter::GetHealthValues(float& Health, float& MaxHealth)
{
	Health = BaseAttributeSetComp->GetHealth();
	MaxHealth = BaseAttributeSetComp->GetMaxHealth();
}

void ABaseCharacter::GetManaValues(float& Mana, float& MaxMana)
{
	Mana = BaseAttributeSetComp->GetMana();
	MaxMana = BaseAttributeSetComp->GetMaxMana();
}

void ABaseCharacter::GetStaminaValues(float& Stamina, float& MaxStamina)
{
	Stamina = BaseAttributeSetComp->GetStamina();
	MaxStamina = BaseAttributeSetComp->GetMaxStamina();
}

void ABaseCharacter::OnHealthChangeNative(const FOnAttributeChangeData& Data)
{
	OnHealthChaged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnManaChangeNative(const FOnAttributeChangeData& Data)
{
	OnManaChaged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnStaminaChangeNative(const FOnAttributeChangeData& Data)
{
	OnStaminaChaged(Data.OldValue, Data.NewValue);
}

