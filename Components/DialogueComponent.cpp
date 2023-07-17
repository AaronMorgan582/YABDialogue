// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Components/DialogueComponent.h"
#include "Test/AnimalNPC.h"

// Sets default values for this component's properties
UDialogueComponent::UDialogueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	
	//Public variables; TArrays do not need to be initialized.
	QuestNPC = false;
	MinFoodCount = 0;
	MaxFoodCount = 0;

	//Protected variables.
	DialogueState = 0;
	Index = 0;
	AmountNeeded = 0;

}


// Called when the game starts
void UDialogueComponent::BeginPlay()
{
	Super::BeginPlay();
	Index = 0;

	check(DialogueUIWidget);
	UWorld* World = GetWorld();
	check(World);
	PlayerController = World->GetFirstPlayerController();
	check(PlayerController);

	DialogueUI = CreateWidget<UDialogueBoxWidget>(PlayerController, DialogueUIWidget);
	DialogueUI->bIsFocusable = true;
	DialogueUI->AddToViewport(6);
	DialogueUI->DialogueBoxCanvas->SetVisibility(ESlateVisibility::Hidden);
}


// Called every frame
void UDialogueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UDialogueComponent::DisplayDialogue() {
	switch (DialogueState) {
		case 0:
			GetDialogue(BeginDialogue);
			break;
		case 1:
			GetDialogue(ProgressDialogue);
			break;
		case 2:
			GetDialogue(EndDialogue);
			break;
	}	
}

void UDialogueComponent::GetDialogue(const TArray<FString> &Dialogue) {
	if (Index < Dialogue.Num()) {
		check(DialogueUI);
		DialogueUI->DialogueBoxCanvas->SetVisibility(ESlateVisibility::Visible);

		DisplayButtons();
		DisplayNPCImage();

		DialogueUI->DialogueText->SetText(FText::FromString(Dialogue[Index]));
		++Index;
	}
	else {
		check(DialogueUI);
		DialogueUI->DialogueBoxCanvas->SetVisibility(ESlateVisibility::Hidden);
		Index = 0;
	}
}

/* This function displays the Accept and Reject buttons on the final "entry" of 
   the starting dialogue (aka the BeginDialogue array) */
void UDialogueComponent::DisplayButtons()
{
	if (DialogueState != 0 || !QuestNPC) {
		UE_LOG(LogTemp, Warning, TEXT("Dialogue State is: %d"), DialogueState);
		return; 
	}

	if (Index == (BeginDialogue.Num() - 1)) {
		
		PlayerController->SetShowMouseCursor(true);
		FInputModeUIOnly UiInputMode;
		PlayerController->SetInputMode(UiInputMode);

		DialogueUI->AcceptButton->SetVisibility(ESlateVisibility::Visible);
		DialogueUI->RejectButton->SetVisibility(ESlateVisibility::Visible);

		DialogueUI->AcceptButton->OnClicked.AddDynamic(this, &UDialogueComponent::QuestAccept);
		DialogueUI->RejectButton->OnClicked.AddDynamic(this, &UDialogueComponent::HideDialogueBox);
	}
	else { return; }
}

void UDialogueComponent::QuestAccept()
{
	HideDialogueBox();
	++DialogueState;
}

void UDialogueComponent::HideDialogueBox()
{
	DialogueUI->DialogueBoxCanvas->SetVisibility(ESlateVisibility::Hidden);
	DialogueUI->AcceptButton->SetVisibility(ESlateVisibility::Hidden);
	DialogueUI->RejectButton->SetVisibility(ESlateVisibility::Hidden);

	PlayerController->SetShowMouseCursor(false);
	FInputModeGameOnly InputModeGame;
	PlayerController->SetInputMode(InputModeGame);
}

void UDialogueComponent::DisplayNPCImage()
{
	class AAnimalNPC* Owner = Cast<AAnimalNPC>(GetOwner());
	ensureMsgf(Owner, TEXT("Cast to Animal NPC failed, ensure this component is set to the proper object. DialogueComponent.cpp, Line 114"));

	DialogueUI->NPCPortrait->SetBrushFromTexture(Owner->Portrait);
	
}


