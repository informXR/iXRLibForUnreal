// Copyright Epic Games, Inc. All Rights Reserved.

#include "IXRLib.h"

#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FIXRLibModule"

void FIXRLibModule::StartupModule()
{
	static void* v_Sqlite_dllHandle = nullptr;
	static void* v_Zlib_dllHandle = nullptr;
	static void* v_LibCurl_dllHandle = nullptr;
	static void* v_IXR_dllHandle = nullptr;

	if (!v_Sqlite_dllHandle)
	{
		FString DllDirectory = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("iXRLib"))->GetBaseDir(), TEXT("Source/ThirdParty/Win64/libraries"));
		v_Sqlite_dllHandle = FPlatformProcess::GetDllHandle(*FPaths::Combine(DllDirectory, TEXT("sqlite3x64.dll")));
		UE_LOG(LogTemp, Warning, TEXT("Sqlite Dll loaded"));
	}
	if (!v_Zlib_dllHandle)
	{
		FString DllDirectory = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("iXRLib"))->GetBaseDir(), TEXT("Source/ThirdParty/Win64/libraries"));
		v_Zlib_dllHandle = FPlatformProcess::GetDllHandle(*FPaths::Combine(DllDirectory, TEXT("libcurl.dll")));
		UE_LOG(LogTemp, Warning, TEXT("Zlib Dll loaded"));
	}
	if (!v_LibCurl_dllHandle)
	{
		FString DllDirectory = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("iXRLib"))->GetBaseDir(), TEXT("Source/ThirdParty/Win64/libraries"));
		v_LibCurl_dllHandle = FPlatformProcess::GetDllHandle(*FPaths::Combine(DllDirectory, TEXT("libcurl.dll")));
		UE_LOG(LogTemp, Warning, TEXT("LibCurl Dll loaded"));
	}
	if (!v_IXR_dllHandle)
	{
		FString DllDirectory = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("iXRLib"))->GetBaseDir(), TEXT("Source/ThirdParty/Win64/libraries"));
		v_IXR_dllHandle = FPlatformProcess::GetDllHandle(*FPaths::Combine(DllDirectory, TEXT("iXRLibShared.dll")));
		UE_LOG(LogTemp, Warning, TEXT("IXRLib Dll loaded"));
	}
}

void FIXRLibModule::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FIXRLibModule, IXRLib)