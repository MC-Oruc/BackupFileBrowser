// Copyright <--\, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BackupFileBrowserEditor : ModuleRules
{
	public BackupFileBrowserEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"ContentBrowserData",
				"ContentBrowserFileDataSource",
				"UnrealEd",
			}
		);
	}
}
