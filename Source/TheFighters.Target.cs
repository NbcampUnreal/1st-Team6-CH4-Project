

using UnrealBuildTool;
using System.Collections.Generic;

public class TheFightersTarget : TargetRules
{
	public TheFightersTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "TheFighters" } );
	}
}
