using UnrealBuildTool;

public class AdaptiveAI : ModuleRules
{
	public AdaptiveAI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core", "CoreUObject", "Engine", "InputCore", "AIModule", 
			"GameplayTasks", "NavigationSystem", "UMG"
		});
		PrivateDependencyModuleNames.AddRange(new string[] {
			"GameplayAbilities", "GameplayTags"
		});
	}
}