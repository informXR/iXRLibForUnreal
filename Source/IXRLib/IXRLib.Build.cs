// Copyright Epic Games, Inc. All Rights Reserved.
using System.IO;
using Microsoft.Extensions.Logging;
using UnrealBuildTool;

#if UE_5_0_OR_LATER
using EpicGames.Core;

#else
using Tools.DotNETCommon;
#endif

public class AbxrLib : ModuleRules
{
	public AbxrLib(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[] { }
		);


		PrivateIncludePaths.AddRange(
			new string[] { }
		);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"Projects",
				"DeveloperSettings",
			}
		);

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
				{ }
		);
		AddEngineThirdPartyPrivateStaticDependencies(Target, "libcurl");
		// AddEngineThirdPartyPrivateStaticDependencies(Target, "OpenSSL");
		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "AbxrLib_Android_UPL.xml"));
			// PublicAdditionalLibraries.Add(PluginPath + "libAbxrLibShared.so");
			
			PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "../ThirdParty", Target.Platform.ToString(), "includes"));
			
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "../ThirdParty", Target.Platform.ToString(), "libraries/libAbxrLibShared.so"));
			RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "../ThirdParty", Target.Platform.ToString(), "libraries/libAbxrLibShared.so"));
			
			PublicDefinitions.Add("_UNIX");
		}
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "../ThirdParty", Target.Platform.ToString(), "includes"));
			HandleWindows(Target);
		}
	}
	

	void HandleWindows(ReadOnlyTargetRules Target)
	{
		// LoadThirdPartyLibrary("AbxrLibStatic", Target);
		LoadThirdPartyLibrary("AbxrLibShared", Target);
		PublicDelayLoadDLLs.Add("AbxrLibShared.dll");
		PublicDelayLoadDLLs.Add("libcurl.dll");
		PublicDelayLoadDLLs.Add("sqlite3x64.dll");
		PublicDelayLoadDLLs.Add("zlib1.dll");
		RuntimeDependencies.Add("AbxrLibShared.pdb");
		RuntimeDependencies.Add("AbxrLibStatic.pdb");
	}
	public void LoadThirdPartyLibrary(string libname, ReadOnlyTargetRules Target)
	{
		var StaticLibExtension = string.Empty;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			StaticLibExtension = ".lib";
		}

		var ThirdPartyPath = Path.Combine(ModuleDirectory, "../ThirdParty", Target.Platform.ToString());
		var LibrariesPath = Path.Combine(ThirdPartyPath, "libraries");
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, libname + StaticLibExtension));
		}
	}
}