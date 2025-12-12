#include "BehaviorTree/Tasks/BTTask_AdaptivePursuit.h"
#include "AI/AdaptiveAIController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_AdaptivePursuit::UBTTask_AdaptivePursuit()
{
	NodeName = "Adaptive Pursuit";
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_AdaptivePursuit::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return EBTNodeResult::InProgress;
}

void UBTTask_AdaptivePursuit::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AAdaptiveAIController* AIController = Cast<AAdaptiveAIController>(OwnerComp.GetAIOwner());
	AActor* Target = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(GetSelectedBlackboardKey()));

	if (!AIController || !Target)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	ACharacter* AIChar = Cast<ACharacter>(AIController->GetPawn());
	if (AIChar)
	{
		float DistToTarget = FVector::Dist(AIChar->GetActorLocation(), Target->GetActorLocation());
		if (DistToTarget > SprintDistanceThreshold)
		{
			AIChar->GetCharacterMovement()->MaxWalkSpeed = 600.0f; // Sprint
		}
		else
		{
			AIChar->GetCharacterMovement()->MaxWalkSpeed = 300.0f; // Normal run
		}

		AIController->MoveToActor(Target, 100.0f);
		
		// If close enough, we could succeed, but pursuit usually continues until condition fails
		if (DistToTarget < 150.0f)
		{
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		}
	}
}
