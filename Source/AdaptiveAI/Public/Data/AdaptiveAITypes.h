#pragma once
#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "AdaptiveAITypes.generated.h"

UENUM(BlueprintType)
enum class EAIBehaviorState : uint8
{
	Idle, Patrolling, Investigating, Chasing, Flanking, Seeking, InCover, Retreating, Attacking
};

UENUM(BlueprintType)
enum class EAIAlertLevel : uint8
{
	Unaware, Suspicious, Alert, Combat
};

UENUM(BlueprintType)
enum class ETacticalPosition : uint8
{
	None, Cover, FlankLeft, FlankRight, HighGround, Ambush
};

USTRUCT(BlueprintType)
struct ADAPTIVEAI_API FAdaptiveAIConfig
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseMovementSpeed = 300.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SightRadius = 1500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HearingRadius = 800.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAIStateChanged, EAIBehaviorState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTargetDetected, AActor*, DetectedActor, FVector, Location);
