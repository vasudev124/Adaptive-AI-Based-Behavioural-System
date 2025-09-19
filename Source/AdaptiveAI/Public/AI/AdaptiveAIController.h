#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Data/AdaptiveAITypes.h"
#include "AdaptiveAIController.generated.h"

UCLASS()
class ADAPTIVEAI_API AAdaptiveAIController : public AAIController
{
	GENERATED_BODY()

public:
	AAdaptiveAIController();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI Components")
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;

public:
	UFUNCTION(BlueprintCallable, Category = "AI Blackboard")
	void SetTargetActor(AActor* NewTarget);
	UFUNCTION(BlueprintCallable, Category = "AI Blackboard")
	AActor* GetTargetActor() const;
	UFUNCTION(BlueprintCallable, Category = "AI Blackboard")
	void SetTargetLocation(const FVector& NewLocation);
	UFUNCTION(BlueprintCallable, Category = "AI Blackboard")
	void SetBehaviorState(EAIBehaviorState NewState);
	UFUNCTION(BlueprintCallable, Category = "AI Blackboard")
	void SetAlertLevel(EAIAlertLevel NewAlertLevel);

private:
	TWeakObjectPtr<class AAdaptiveNPCCharacter> ControlledNPC;
};
