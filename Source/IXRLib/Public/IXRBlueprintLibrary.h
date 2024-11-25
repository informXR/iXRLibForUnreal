// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// #include "Windows/AllowWindowsPlatformTypes.h"
#if PLATFORM_ANDROID
THIRD_PARTY_INCLUDES_START

THIRD_PARTY_INCLUDES_END
// #include "Windows/HideWindowsPlatformTypes.h"
#endif
#include <Interface.h>

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IXRBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class IXRLIB_API UIXRBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable)
	static FString GetConvertedString(FString String);
	
	UFUNCTION(BlueprintCallable)
	static void StartIXRLib_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void iXRLibInitStart_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void iXRLibInitEnd_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int Authenticate_BFL(const FString szAppId, const FString szOrgId, const FString szDeviceId, const FString szAuthSecret, const int ePartner);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int ReAuthenticate_BFL(const bool bObtainAuthSecret);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int ForceSendUnsentSynchronous_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void CaptureTimeStamp_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void UnCaptureTimeStamp_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int LogDebugSynchronous_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int LogDebug_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int LogInfoSynchronous_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int LogInfo_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int LogWarnSynchronous_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int LogWarn_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int LogErrorSynchronous_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int LogError_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int LogCriticalSynchronous_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int LogCritical_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int EventSynchronous_BFL(const FString szMessage, const FString szdictMeta);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int Event_BFL(const FString szMessage, const FString szdictMeta);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int AddAIProxySynchronous_BFL(const FString szPrompt, const FString szPastMessages, const FString szLMMProvider);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int AddAIProxy_BFL(const FString szPrompt, const FString szPastMessages, const FString szLMMProvider);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int AddTelemetryEntrySynchronous_BFL(const FString szName, const FString szdictData);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int AddTelemetryEntry_BFL(const FString szName, const FString szdictData);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static bool PlatformIsWindows_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString GetApiToken_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetApiToken_BFL(const FString szApiToken);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString GetApiSecret_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetApiSecret_BFL(const FString szApiSecret);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString GetAppID_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetAppID_BFL(const FString szAppID);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString GetOrgID_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetOrgID_BFL(const FString szOrgID);
	
	// UFUNCTION(BlueprintCallable, Category = "iXRLib")
	// CSharpDateTime GetTokenExpiration_BFL();
	//
	// UFUNCTION(BlueprintCallable, Category = "iXRLib")
	// void SetTokenExpiration_BFL(const CSharpDateTime dtTokenExpiration);

	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static bool TokenExpirationImminent_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int GetPartner_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetPartner_BFL(const int ePartner);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString GetOsVersion_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetOsVersion_BFL(const FString szOsVersion);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString GetIpAddress_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetIpAddress_BFL(const FString szIpAddress);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString GetXrdmVersion_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetXrdmVersion_BFL(const FString szXrdmVersion);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString GetAppVersion_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetAppVersion_BFL(const FString szAppVersion);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString GetUnrealVersion_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetUnrealVersion_BFL(const FString szUnityVersion);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString GetDeviceModel_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetDeviceModel_BFL(const FString szDeviceModel);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString GetTags_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetTags_BFL(const FString szlszTags);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString GetGeoLocation_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetGeoLocation_BFL(const FString szdictGeoLocation);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString StorageGetDefaultEntryAsString_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString StorageGetEntryAsString_BFL(const FString wszName);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int StorageSetDefaultEntryFromString_BFL(const FString wszStorageEntry, const bool bKeepLatest, const FString wszOrigin, const bool bSessionData);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int StorageSetEntryFromString_BFL(const FString wszName, const FString wszStorageEntry, const bool bKeepLatest, const FString wszOrigin, const bool bSessionData);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int StorageRemoveDefaultEntry_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int StorageRemoveEntry_BFL(const FString wszName);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int StorageRemoveMultipleEntries_BFL(const bool bSessionOnly);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString GetRestUrl_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetRestUrl_BFL(const FString szValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int GetSendRetriesOnFailure_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetSendRetriesOnFailure_BFL(int nValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static double GetSendRetryInterval_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetSendRetryInterval_BFL(double tsValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static double GetSendNextBatchWait_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetSendNextBatchWait_BFL(double tsValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static double GetStragglerTimeout_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetStragglerTimeout_BFL(double tsValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int GetEventsPerSendAttempt_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetEventsPerSendAttempt_BFL(int nValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int GetLogsPerSendAttempt_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetLogsPerSendAttempt_BFL(int nValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int GetTelemetryEntriesPerSendAttempt_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetTelemetryEntriesPerSendAttempt_BFL(int nValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int GetStorageEntriesPerSendAttempt_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetStorageEntriesPerSendAttempt_BFL(int nValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static double GetPruneSentItemsOlderThan_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetPruneSentItemsOlderThan_BFL(double tsValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int GetMaximumCachedItems_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetMaximumCachedItems_BFL(int nValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static bool GetRetainLocalAfterSent_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetRetainLocalAfterSent_BFL(bool bValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static bool GetReAuthenticateBeforeTokenExpires_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetReAuthenticateBeforeTokenExpires_BFL(bool bValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static bool GetUseDatabase_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetUseDatabase_BFL(bool bValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static bool ReadConfig_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static bool GetAuthSecretCSharp_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetGetAuthSecretCallbackRet_BFL(const FString szAuthSecret);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static void SetServingCSharp_BFL(const bool bServingCSharp);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static bool GetNextDiagnosticString_BFL(FString& pbstrString);

	// TODO: add enum class instead of unit8
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static uint8 HTTPGet_BFL(const FString bstrUrl, FString& pbstrResponse);

	// TODO: add enum class instead of unit8
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static uint8 HTTPPost_BFL(const FString bstrUrl, FString& pbstrResponse);

	// TODO:
	// UFUNCTION(BlueprintCallable, Category = "iXRLib")
	// int iXRLibAnalyticsTests_BFL(int argc, char* argv[]);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static int iXRLibAnalyticsTestsInterop_BFL(const FString bstrCommandLine);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	static FString TestGetAuthSecretCallback_BFL();
	
};
