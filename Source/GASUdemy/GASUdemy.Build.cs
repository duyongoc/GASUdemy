// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GASUdemy : ModuleRules
{
    public GASUdemy(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
    }
}
