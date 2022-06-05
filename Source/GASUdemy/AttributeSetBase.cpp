// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffect.h"


UAttributeSetBase::UAttributeSetBase()
	:Health(100.0f)
{

}

void UAttributeSetBase::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	UE_LOG(LogTemp, Warning, TEXT("i took damaged"));

	if (Data.EvaluatedData.Attribute.GetUProperty() ==
		FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health)))
	{
		UE_LOG(LogTemp, Warning, TEXT("i took damage: %f"), Health.GetCurrentValue());
	}
}
