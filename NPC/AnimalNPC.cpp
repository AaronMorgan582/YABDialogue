// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/AnimalNPC.h"
#include "Characters/Components/DialogueComponent.h"
#include "Engine/SkeletalMesh.h"

// Sets default values
AAnimalNPC::AAnimalNPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;	
}

// Called when the game starts or when spawned
void AAnimalNPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnimalNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

