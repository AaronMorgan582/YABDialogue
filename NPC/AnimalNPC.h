// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "AnimalNPC.generated.h"

UCLASS()
class YAB_PROJECT_API AAnimalNPC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAnimalNPC();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Info")
		class UTexture2D* QuestItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC Info")
		class UTexture2D* Portrait;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC Info")
		FString Name;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
