#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_AdaptivePursuit.generated.h"

UCLASS()
class ADAPTIVEAI_API UBTTask_AdaptivePursuit : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_AdaptivePursuit();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Pursuit")
	float SprintDistanceThreshold = 800.0f;
};
