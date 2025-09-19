#include "AI/AdaptiveAIController.h"
#include "AI/AdaptiveNPCCharacter.h"
#include "BehaviorTree/BehaviorTree.h"

AAdaptiveAIController::AAdaptiveAIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AAdaptiveAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AAdaptiveAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	ControlledNPC = Cast<AAdaptiveNPCCharacter>(InPawn);

	if (ControlledNPC.IsValid() && ControlledNPC->BehaviorTree)
	{
		if (ControlledNPC->BehaviorTree->BlackboardAsset)
		{
			BlackboardComponent->InitializeBlackboard(*ControlledNPC->BehaviorTree->BlackboardAsset);
			BehaviorTreeComponent->StartTree(*ControlledNPC->BehaviorTree);
		}
	}
}

void AAdaptiveAIController::SetTargetActor(AActor* NewTarget)
{
	if (BlackboardComponent)
	{
		BlackboardComponent->SetValueAsObject(TEXT("TargetActor"), NewTarget);
	}
}

AActor* AAdaptiveAIController::GetTargetActor() const
{
	if (BlackboardComponent)
	{
		return Cast<AActor>(BlackboardComponent->GetValueAsObject(TEXT("TargetActor")));
	}
	return nullptr;
}

void AAdaptiveAIController::SetTargetLocation(const FVector& NewLocation)
{
	if (BlackboardComponent)
	{
		BlackboardComponent->SetValueAsVector(TEXT("TargetLocation"), NewLocation);
	}
}

void AAdaptiveAIController::SetBehaviorState(EAIBehaviorState NewState)
{
	if (BlackboardComponent)
	{
		BlackboardComponent->SetValueAsEnum(TEXT("BehaviorState"), static_cast<uint8>(NewState));
	}
}

void AAdaptiveAIController::SetAlertLevel(EAIAlertLevel NewAlertLevel)
{
	if (BlackboardComponent)
	{
		BlackboardComponent->SetValueAsEnum(TEXT("AlertLevel"), static_cast<uint8>(NewAlertLevel));
	}
}
