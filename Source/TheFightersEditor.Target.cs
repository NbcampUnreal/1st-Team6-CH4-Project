

using UnrealBuildTool;
using System.Collections.Generic;

public class TheFightersEditorTarget : TargetRules
{
	public TheFightersEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "TheFighters" } );
	}
}
