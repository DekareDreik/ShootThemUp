// Shoot Them Up Game. Created by DekareDreik


#include "STU_GameModeBase.h"
#include "STUCharacter.h"
#include "STUPlayerController.h"
#include "UI/STUGameHUD.h"

ASTU_GameModeBase::ASTU_GameModeBase() 
{
	DefaultPawnClass = ASTUCharacter::StaticClass();
	PlayerControllerClass = ASTUPlayerController::StaticClass();
	HUDClass = ASTUGameHUD::StaticClass();
}

