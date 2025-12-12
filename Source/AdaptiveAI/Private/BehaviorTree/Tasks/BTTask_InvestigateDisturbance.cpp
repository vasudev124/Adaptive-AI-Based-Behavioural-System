#include "BehaviorTree/Tasks/BTTask_InvestigateDisturbance.h"
#include "AI/AdaptiveAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"

UBTTask_InvestigateDisturbance::UBTTask_InvestigateDisturbance()
{
	NodeName = "Investigate Disturbance";
}

EBTNodeResult::Type UBTTask_InvestigateDisturbance::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAdaptiveAIController* AIController = Cast<AAdaptiveAIController>(OwnerComp.GetAIOwner());
	FVector TargetLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(GetSelectedBlackboardKey());

	if (AIController)
	{
		AIController->MoveToLocation(TargetLocation, 50.0f);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
