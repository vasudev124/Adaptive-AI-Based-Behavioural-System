#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_InvestigateDisturbance.generated.h"

UCLASS()
class ADAPTIVEAI_API UBTTask_InvestigateDisturbance : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_InvestigateDisturbance();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Investigation")
	float InvestigationRadius = 200.0f;
};
