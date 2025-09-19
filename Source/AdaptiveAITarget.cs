using UnrealBuildTool;
public class AdaptiveAITarget : TargetRules
{
	public AdaptiveAITarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		ExtraModuleNames.Add("AdaptiveAI");
	}
}