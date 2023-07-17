// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "DialogueBoxWidget.generated.h"

/**
 * 
 */
UCLASS()
class YAB_PROJECT_API UDialogueBoxWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, meta=(BindWidget))
		class UCanvasPanel* DialogueBoxCanvas;

	UPROPERTY(EditAnywhere, meta=(BindWidget), Category = "Images")
		class UImage* PortraitBackground;

	UPROPERTY(EditAnywhere, meta=(BindWidget), Category = "Images")
		class UImage* NPCPortrait;
	
	UPROPERTY(EditAnywhere, meta=(BindWidget), Category = "Images")
		class UImage* TextBoxWindow;

	UPROPERTY(EditAnywhere, meta=(BindWidget), Category = "Text")
		class UTextBlock* DialogueText;

	UPROPERTY(EditAnywhere, meta=(BindWidget), Category = "Buttons")
		class UButton* AcceptButton;

	UPROPERTY(EditAnywhere, meta=(BindWidget), Category = "Buttons")
		class UButton* RejectButton;	
};
