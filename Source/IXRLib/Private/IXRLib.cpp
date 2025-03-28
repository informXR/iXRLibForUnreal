// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbxrLib.h"

#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FAbxrLibModule"

void FAbxrLibModule::StartupModule()
{
	static void* v_Sqlite_dllHandle = nullptr;
	static void* v_Zlib_dllHandle = nullptr;
	static void* v_LibCurl_dllHandle = nullptr;
	static void* v_Abxr_dllHandle = nullptr;

	if (!v_Sqlite_dllHandle)
	{
		FString DllDirectory = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("AbxrLib"))->GetBaseDir(), TEXT("Source/ThirdParty/Win64/libraries"));
		v_Sqlite_dllHandle = FPlatformProcess::GetDllHandle(*FPaths::Combine(DllDirectory, TEXT("sqlite3x64.dll")));
		UE_LOG(LogTemp, Warning, TEXT("Sqlite Dll loaded"));
	}
	if (!v_Zlib_dllHandle)
	{
		FString DllDirectory = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("AbxrLib"))->GetBaseDir(), TEXT("Source/ThirdParty/Win64/libraries"));
		v_Zlib_dllHandle = FPlatformProcess::GetDllHandle(*FPaths::Combine(DllDirectory, TEXT("libcurl.dll")));
		UE_LOG(LogTemp, Warning, TEXT("Zlib Dll loaded"));
	}
	if (!v_LibCurl_dllHandle)
	{
		FString DllDirectory = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("AbxrLib"))->GetBaseDir(), TEXT("Source/ThirdParty/Win64/libraries"));
		v_LibCurl_dllHandle = FPlatformProcess::GetDllHandle(*FPaths::Combine(DllDirectory, TEXT("libcurl.dll")));
		UE_LOG(LogTemp, Warning, TEXT("LibCurl Dll loaded"));
	}
	if (!v_Abxr_dllHandle)
	{
		FString DllDirectory = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("AbxrLib"))->GetBaseDir(), TEXT("Source/ThirdParty/Win64/libraries"));
		v_Abxr_dllHandle = FPlatformProcess::GetDllHandle(*FPaths::Combine(DllDirectory, TEXT("AbxrLibShared.dll")));
		UE_LOG(LogTemp, Warning, TEXT("AbxrLib Dll loaded"));
	}
}

void FAbxrLibModule::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAbxrLibModule, AbxrLib)