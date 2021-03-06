// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AttributeSetBase.generated.h"

/**
 *
 */
UCLASS()
class GASUDEMY_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()


public:
	UAttributeSetBase();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData Health;

	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

};
