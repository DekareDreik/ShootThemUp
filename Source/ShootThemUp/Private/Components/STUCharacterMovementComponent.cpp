// Shoot Them Up Game. Created by DekareDreik


#include "Components/STUCharacterMovementComponent.h"
#include "STUCharacter.h"

float USTUCharacterMovementComponent::GetMaxSpeed() const 
{
	const float MaxSpeed = Super::GetMaxSpeed();
	const ASTUCharacter* Player = Cast<ASTUCharacter>(GetPawnOwner());
	return Player && Player->IsRunning() ? MaxSpeed * RunModifier: MaxSpeed;
}