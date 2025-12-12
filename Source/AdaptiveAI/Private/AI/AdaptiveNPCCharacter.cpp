#include "AI/AdaptiveNPCCharacter.h"
#include "AI/AdaptiveAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

AAdaptiveNPCCharacter::AAdaptiveNPCCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AAdaptiveAIController::StaticClass();
	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComponent"));
	PawnSensingComponent->SightRadius = 1500.0f;
	PawnSensingComponent->HearingThreshold = 600.0f;
	CurrentBehaviorState = EAIBehaviorState::Idle;
	CurrentAlertLevel = EAIAlertLevel::Unaware;
}

void AAdaptiveNPCCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (PawnSensingComponent)
	{
		PawnSensingComponent->OnSeePawn.AddDynamic(this, &AAdaptiveNPCCharacter::OnSeePlayer);
		PawnSensingComponent->OnHearNoise.AddDynamic(this, &AAdaptiveNPCCharacter::OnHearNoise);
		
		// Apply Dynamic Config
		PawnSensingComponent->SightRadius = AIConfig.SightRadius;
		PawnSensingComponent->HearingThreshold = AIConfig.HearingRadius;
	}
	
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = AIConfig.BaseMovementSpeed;
	}

	AdaptiveAIController = Cast<AAdaptiveAIController>(GetController());
}

void AAdaptiveNPCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAdaptiveNPCCharacter::OnSeePlayer(APawn* SeenPawn)
{
	if (SeenPawn && SeenPawn != this)
	{
		SetAlertLevel(EAIAlertLevel::Alert);
		SetBehaviorState(EAIBehaviorState::Chasing);
		if (AdaptiveAIController.IsValid())
		{
			AdaptiveAIController->SetTargetActor(SeenPawn);
		}
		OnTargetDetected.Broadcast(SeenPawn, SeenPawn->GetActorLocation());
	}
}

void AAdaptiveNPCCharacter::OnHearNoise(APawn* NoiseInstigator, const FVector& Location, float Volume)
{
	if (CurrentAlertLevel == EAIAlertLevel::Unaware)
	{
		SetAlertLevel(EAIAlertLevel::Suspicious);
		SetBehaviorState(EAIBehaviorState::Investigating);
	}
}

void AAdaptiveNPCCharacter::SetBehaviorState(EAIBehaviorState NewState)
{
	CurrentBehaviorState = NewState;
	if (AdaptiveAIController.IsValid())
	{
		AdaptiveAIController->SetBehaviorState(NewState);
	}
	OnAIStateChanged.Broadcast(NewState);
}

void AAdaptiveNPCCharacter::SetAlertLevel(EAIAlertLevel NewAlertLevel)
{
	CurrentAlertLevel = NewAlertLevel;
	if (AdaptiveAIController.IsValid())
	{
		AdaptiveAIController->SetAlertLevel(NewAlertLevel);
	}
}

AAdaptiveAIController* AAdaptiveNPCCharacter::GetAdaptiveAIController() const
{
	return AdaptiveAIController.Get();
}
