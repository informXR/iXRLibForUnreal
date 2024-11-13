// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
	static void StartIXRLib_BFL();

	UFUNCTION(BlueprintCallable)
	static void iXRForceSendUnsentSynchronous();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void iXRLibInitStart_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void iXRLibInitEnd_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int Authenticate_BFL(const FString szAppId, const FString szOrgId, const FString szDeviceId, const FString szAuthSecret, const int ePartner);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int ReAuthenticate_BFL(const bool bObtainAuthSecret);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int ForceSendUnsentSynchronous_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void CaptureTimeStamp_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void UnCaptureTimeStamp_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int LogDebugSynchronous_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int LogDebug_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int LogInfoSynchronous_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int LogInfo_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int LogWarnSynchronous_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int LogWarn_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int LogErrorSynchronous_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int LogError_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int LogCriticalSynchronous_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int LogCritical_BFL(const FString szText);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int EventSynchronous_BFL(const FString szMessage, const FString szdictMeta);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int Event_BFL(const FString szMessage, const FString szdictMeta);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int AddAIProxySynchronous_BFL(const FString szPrompt, const FString szPastMessages, const FString szLMMProvider);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int AddAIProxy_BFL(const FString szPrompt, const FString szPastMessages, const FString szLMMProvider);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int AddTelemetryEntrySynchronous_BFL(const FString szName, const FString szdictData);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int AddTelemetryEntry_BFL(const FString szName, const FString szdictData);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	bool PlatformIsWindows_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString GetApiToken_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetApiToken_BFL(const FString szApiToken);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString GetApiSecret_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetApiSecret_BFL(const FString szApiSecret);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString GetAppID_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetAppID_BFL(const FString szAppID);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString GetOrgID_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetOrgID_BFL(const FString szOrgID);
	
	// UFUNCTION(BlueprintCallable, Category = "iXRLib")
	// CSharpDateTime GetTokenExpiration_BFL();
	//
	// UFUNCTION(BlueprintCallable, Category = "iXRLib")
	// void SetTokenExpiration_BFL(const CSharpDateTime dtTokenExpiration);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	bool TokenExpirationImminent_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int GetPartner_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetPartner_BFL(const int ePartner);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString GetOsVersion_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetOsVersion_BFL(const FString szOsVersion);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString GetIpAddress_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetIpAddress_BFL(const FString szIpAddress);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString GetXrdmVersion_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetXrdmVersion_BFL(const FString szXrdmVersion);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString GetAppVersion_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetAppVersion_BFL(const FString szAppVersion);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString GetUnrealVersion_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetUnrealVersion_BFL(const FString szUnityVersion);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString GetDeviceModel_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetDeviceModel_BFL(const FString szDeviceModel);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString GetTags_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetTags_BFL(const FString szlszTags);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString GetGeoLocation_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetGeoLocation_BFL(const FString szdictGeoLocation);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString StorageGetDefaultEntryAsString_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString StorageGetEntryAsString_BFL(const FString wszName);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int StorageSetDefaultEntryFromString_BFL(const FString wszStorageEntry, const bool bKeepLatest, const FString wszOrigin, const bool bSessionData);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int StorageSetEntryFromString_BFL(const FString wszName, const FString wszStorageEntry, const bool bKeepLatest, const FString wszOrigin, const bool bSessionData);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int StorageRemoveDefaultEntry_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int StorageRemoveEntry_BFL(const FString wszName);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int StorageRemoveMultipleEntries_BFL(const bool bSessionOnly);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString GetRestUrl_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetRestUrl_BFL(const FString szValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int GetSendRetriesOnFailure_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetSendRetriesOnFailure_BFL(int nValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	double GetSendRetryInterval_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetSendRetryInterval_BFL(double tsValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	double GetSendNextBatchWait_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetSendNextBatchWait_BFL(double tsValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	double GetStragglerTimeout_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetStragglerTimeout_BFL(double tsValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int GetEventsPerSendAttempt_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetEventsPerSendAttempt_BFL(int nValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int GetLogsPerSendAttempt_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetLogsPerSendAttempt_BFL(int nValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int GetTelemetryEntriesPerSendAttempt_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetTelemetryEntriesPerSendAttempt_BFL(int nValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int GetStorageEntriesPerSendAttempt_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetStorageEntriesPerSendAttempt_BFL(int nValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	double GetPruneSentItemsOlderThan_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetPruneSentItemsOlderThan_BFL(double tsValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int GetMaximumCachedItems_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetMaximumCachedItems_BFL(int nValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	bool GetRetainLocalAfterSent_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetRetainLocalAfterSent_BFL(bool bValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	bool GetReAuthenticateBeforeTokenExpires_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetReAuthenticateBeforeTokenExpires_BFL(bool bValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	bool GetUseDatabase_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetUseDatabase_BFL(bool bValue);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	bool ReadConfig_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	bool GetAuthSecretCSharp_BFL();
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetGetAuthSecretCallbackRet_BFL(const FString szAuthSecret);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	void SetServingCSharp_BFL(const bool bServingCSharp);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	bool GetNextDiagnosticString_BFL(FString& pbstrString);

	// TODO: add enum class instead of unit8
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	uint8 HTTPGet_BFL(const FString bstrUrl, FString& pbstrResponse);

	// TODO: add enum class instead of unit8
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	uint8 HTTPPost_BFL(const FString bstrUrl, FString& pbstrResponse);

	// TODO:
	// UFUNCTION(BlueprintCallable, Category = "iXRLib")
	// int iXRLibAnalyticsTests_BFL(int argc, char* argv[]);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	int iXRLibAnalyticsTestsInterop_BFL(const FString bstrCommandLine);
	
	UFUNCTION(BlueprintCallable, Category = "iXRLib")
	FString TestGetAuthSecretCallback_BFL();
	
};
