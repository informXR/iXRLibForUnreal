// Copyright Epic Games, Inc. All Rights Reserved.

#include "IXRLib.h"

#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FIXRLibModule"

void FIXRLibModule::StartupModule()
{
	static void* v_dllHandle = nullptr;

	if (!v_dllHandle)
	{
		FString DllDirectory = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("TestPlugin"))->GetBaseDir(), TEXT("Source/ThirdParty/Win64/libraries"));
		v_dllHandle = FPlatformProcess::GetDllHandle(*FPaths::Combine(DllDirectory, TEXT("iXRLibShared.dll")));
		UE_LOG(LogTemp, Warning, TEXT("Dll loaded"));
	}
}

void FIXRLibModule::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FIXRLibModule, IXRLib)