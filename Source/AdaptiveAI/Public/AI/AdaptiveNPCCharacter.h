#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/PawnSensingComponent.h"
#include "Data/AdaptiveAITypes.h"
#include "AdaptiveNPCCharacter.generated.h"

UCLASS()
class ADAPTIVEAI_API AAdaptiveNPCCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AAdaptiveNPCCharacter();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UPawnSensingComponent> PawnSensingComponent;

public:
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	TObjectPtr<class UBehaviorTree> BehaviorTree;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Config")
	FAdaptiveAIConfig AIConfig;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI State")
	EAIBehaviorState CurrentBehaviorState;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI State")
	EAIAlertLevel CurrentAlertLevel;

	UPROPERTY(BlueprintAssignable)
	FOnAIStateChanged OnAIStateChanged;
	UPROPERTY(BlueprintAssignable)
	FOnTargetDetected OnTargetDetected;

	UFUNCTION()
	void OnSeePlayer(APawn* SeenPawn);
	UFUNCTION()
	void OnHearNoise(APawn* NoiseInstigator, const FVector& Location, float Volume);
	UFUNCTION(BlueprintCallable)
	void SetBehaviorState(EAIBehaviorState NewState);
	UFUNCTION(BlueprintCallable)
	void SetAlertLevel(EAIAlertLevel NewAlertLevel);
	class AAdaptiveAIController* GetAdaptiveAIController() const;
	EAIAlertLevel GetAlertLevel() const { return CurrentAlertLevel; }

private:
	TWeakObjectPtr<class AAdaptiveAIController> AdaptiveAIController;
};
