// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SIS457_L01 : ModuleRules
{
	public SIS457_L01(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
