// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShrimpOK : ModuleRules
{
	public ShrimpOK(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay", 
			"NavigationSystem", 
			"AIModule", 
			"Niagara", 
			"EnhancedInput" 
		});

		PublicIncludePaths.AddRange(
		new string[]
		{
				"ShrimpOK",
		});

	}
}
