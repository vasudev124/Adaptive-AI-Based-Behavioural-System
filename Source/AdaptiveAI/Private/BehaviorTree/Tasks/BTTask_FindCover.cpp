#include "BehaviorTree/Tasks/BTTask_FindCover.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI/AdaptiveAIController.h"
#include "NavigationSystem.h"

UBTTask_FindCover::UBTTask_FindCover()
{
	NodeName = TEXT("Find Cover");
	CoverLocationKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_FindCover, CoverLocationKey));
}

EBTNodeResult::Type UBTTask_FindCover::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAdaptiveAIController* AIController = Cast<AAdaptiveAIController>(OwnerComp.GetAIOwner());
	if (!AIController) return EBTNodeResult::Failed;

	APawn* AIPawn = AIController->GetPawn();
	AActor* ThreatActor = AIController->GetTargetActor();
	if (!AIPawn || !ThreatActor) return EBTNodeResult::Failed;

	FVector CoverLocation = FindBestCoverLocation(AIPawn, ThreatActor);
	if (CoverLocation != FVector::ZeroVector)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(CoverLocationKey.SelectedKeyName, CoverLocation);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}

FVector UBTTask_FindCover::FindBestCoverLocation(AActor* AIActor, AActor* ThreatActor) const
{
	if (!AIActor || !ThreatActor) return FVector::ZeroVector;

	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(AIActor->GetWorld());
	if (!NavSys) return FVector::ZeroVector;

	FVector AILocation = AIActor->GetActorLocation();
	FVector ThreatLocation = ThreatActor->GetActorLocation();
	FVector DirectionFromThreat = (AILocation - ThreatLocation).GetSafeNormal();
	FVector CoverLocation = AILocation + (DirectionFromThreat * MaxSearchRadius);

	FNavLocation NavLocation;
	if (NavSys->ProjectPointToNavigation(CoverLocation, NavLocation))
	{
		return NavLocation.Location;
	}
	return FVector::ZeroVector;
}
