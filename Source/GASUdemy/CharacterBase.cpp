// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "AttributeSetBase.h"


ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	abilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	AttributeSetBaseComp = CreateDefaultSubobject<UAttributeSetBase>("AttributeSetBaseComp");
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

}

void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return abilitySystemComp;
}


void ACharacterBase::AquireAbility(TSubclassOf<UGameplayAbility> AblityToAquire)
{
	if (abilitySystemComp)
	{
		if (HasAuthority() && AblityToAquire)
		{
			abilitySystemComp->GiveAbility(FGameplayAbilitySpec(AblityToAquire, 1, 0));
		}

		abilitySystemComp->InitAbilityActorInfo(this, this);
	}
}

