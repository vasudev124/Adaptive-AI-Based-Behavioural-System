using UnrealBuildTool;
public class AdaptiveAIEditorTarget : TargetRules
{
	public AdaptiveAIEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		ExtraModuleNames.Add("AdaptiveAI");
	}
}