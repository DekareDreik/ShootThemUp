// Shoot Them Up Game. Created by DekareDreik


#include "Weapon/STULauncherWeapon.h"
#include "Weapon/STUProjectile.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

void ASTULauncherWeapon::StartFire() 
{
	MakeShoot();
}

void ASTULauncherWeapon::MakeShoot()
{
	if (!GetWorld() || IsAmmoEmpty()) return;

	FVector TraceStart, TraceEnd;
	if (!GetTraceData(TraceStart, TraceEnd)) return;

	FHitResult HitResult;
	MakeHit(HitResult, TraceStart, TraceEnd);

	const FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd;
	const FVector Direction = (EndPoint - GetMuzzleWorldLocation().GetSafeNormal());

	const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
	ASTUProjectile* Projectile = GetWorld()->SpawnActorDeferred<ASTUProjectile>(ProjectileClass, SpawnTransform);

	DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 24, FColor::Red, false, 10.0f);
	DrawDebugLine(GetWorld(), GetMuzzleWorldLocation(), HitResult.ImpactPoint, FColor::Red, false, 10.0f, 0, 3.0f);
	
	if (Projectile)
	{
		Projectile->SetShootDirection(Direction);
		Projectile->SetOwner(GetOwner());
		Projectile->FinishSpawning(SpawnTransform);
	}

	DecreaseAmmo();
}