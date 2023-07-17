// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "UI\DialogueBoxWidget.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogueComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class YAB_PROJECT_API UDialogueComponent : public UActorComponent
{
	GENERATED_BODY()
public:	
	// Sets default values for this component's properties
	UDialogueComponent();

	//Editor accessible - Dialogue variables.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
		TArray<FString> BeginDialogue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
		TArray<FString> ProgressDialogue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
		TArray<FString> EndDialogue;

	//Editor accessible - Quest variables.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Info")
		bool QuestNPC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Info")
		FString QuestItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Info")
		uint8 MinFoodCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Info")
		uint8 MaxFoodCount;
		
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//Dialogue variables.
	UPROPERTY(BlueprintReadWrite)
		uint8 DialogueState;
	UPROPERTY(BlueprintReadWrite)
		uint8 Index;

	UPROPERTY(BlueprintReadOnly, Category = "Player")
		class APlayerController* PlayerController;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
		TSubclassOf<class UDialogueBoxWidget> DialogueUIWidget;
	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
		class UDialogueBoxWidget* DialogueUI;

	//Quest variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Info")
		TSubclassOf<AActor> SpawnedQuestItem;
	UPROPERTY(BlueprintReadWrite)
		uint8 AmountNeeded;
	UPROPERTY(BlueprintReadWrite)
		FString Name;

	//Widget variables.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> QuestEntry;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> ItemTracker;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> UBearEats;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
		void DisplayDialogue();

protected:
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
		void GetDialogue(const TArray<FString> &Dialogue);
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
		void DisplayButtons();
	UFUNCTION(BlueprintCallable, Category = "Quest")
		void QuestAccept();
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
		void HideDialogueBox();
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
		void DisplayNPCImage();
};
