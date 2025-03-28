// Fill out your copyright notice in the Description page of Project Settings.


#include "AbxrBlueprintLibrary.h"

#include "FStringToCharConverter.h"
#include "AbxrDeveloperSettings.h"

char16_t* FStringToChar16Ptr(const FString& UnrealString) {
	UFStringToCharConverter* Converter = NewObject<UFStringToCharConverter>();
	return Converter->Convert(UnrealString);
}

FString Char16PtrToFString(const char16_t* Char16Ptr) {
	UFStringToCharConverter* Converter = NewObject<UFStringToCharConverter>();
	return Converter->ReverseConvert(Char16Ptr);
}

uint32_t IntToUint32(const int UnrealInt) { return static_cast<uint32_t>(UnrealInt); }

FString UAbxrBlueprintLibrary::GetConvertedString(FString String)
{
	char16_t* Char16Ptr = FStringToChar16Ptr(String);
	return Char16PtrToFString(Char16Ptr);
}

void UAbxrBlueprintLibrary::SetConfigValues()
{
	SetRestUrl_BFL(*UAbxrDeveloperSettings::GetAbxrConfig()->restUrl);

	SetSendRetriesOnFailure_BFL(UAbxrDeveloperSettings::GetAbxrConfig()->sendRetriesOnFailure);
	SetSendRetryInterval_BFL(UAbxrDeveloperSettings::GetAbxrConfig()->sendRetryIntervalSeconds);
	SetSendNextBatchWait_BFL(UAbxrDeveloperSettings::GetAbxrConfig()->sendNextBatchWaitSeconds);
	SetStragglerTimeout_BFL(UAbxrDeveloperSettings::GetAbxrConfig()->stragglerTimeoutSeconds);
	SetEventsPerSendAttempt_BFL(UAbxrDeveloperSettings::GetAbxrConfig()->eventsPerSendAttempt);
	SetLogsPerSendAttempt_BFL(UAbxrDeveloperSettings::GetAbxrConfig()->logsPerSendAttempt);
	SetTelemetryEntriesPerSendAttempt_BFL(UAbxrDeveloperSettings::GetAbxrConfig()->telemetryEntriesPerSendAttempt);
	SetStorageEntriesPerSendAttempt_BFL(UAbxrDeveloperSettings::GetAbxrConfig()->storageEntriesPerSendAttempt);
	SetPruneSentItemsOlderThan_BFL(UAbxrDeveloperSettings::GetAbxrConfig()->pruneSentItemsOlderThanHours);
	SetMaximumCachedItems_BFL(UAbxrDeveloperSettings::GetAbxrConfig()->maximumCachedItems);
	SetRetainLocalAfterSent_BFL(UAbxrDeveloperSettings::GetAbxrConfig()->retainLocalAfterSent);
}

void UAbxrBlueprintLibrary::StartAbxrLib_BFL()
{
	AbxrLibInitStart();
	SetConfigValues();

	int StatusIndex = Authenticate_BFL(UAbxrDeveloperSettings::GetAbxrConfig()->appID, UAbxrDeveloperSettings::GetAbxrConfig()->orgID,
			FGuid::NewGuid().ToString(), UAbxrDeveloperSettings::GetAbxrConfig()->authSecret, 0);

	UE_LOG(LogTemp, Warning, TEXT("Authenticated ====> %d"), StatusIndex);
	LogInfo_BFL(TEXT("TestStr"), TEXT(""));
}

void UAbxrBlueprintLibrary::AbxrLibInitStart_BFL()
{
	AbxrLibInitStart();
}

void UAbxrBlueprintLibrary::AbxrLibInitEnd_BFL()
{
	AbxrLibInitEnd();
}

int UAbxrBlueprintLibrary::Authenticate_BFL(const FString szAppId, const FString szOrgId, const FString szDeviceId,
	const FString szAuthSecret, const int ePartner)
{
	return Authenticate(FStringToChar16Ptr(szAppId), FStringToChar16Ptr(szOrgId),
		FStringToChar16Ptr(szDeviceId), FStringToChar16Ptr(szAuthSecret), 0);
}

void UAbxrBlueprintLibrary::KeyboardAuthenticate(FString KeyboardInput, const FOnReceivedResponseSignature& OnReceivedResponseDelegate)
{
	if (KeyboardInput.IsEmpty()) return;
	const char16_t* Char16Ptr = get_SessionAuthMechanism();
	FString InputString = Char16PtrToFString(get_SessionAuthMechanism());
	TMap<FString, FString> AuthMap;
    AuthMap.Add("prompt", KeyboardInput);
    
    if (KeyboardInput.Contains("@"))
    	AuthMap.Add("type", "email");
	else if (KeyboardInput.IsNumeric())
		AuthMap.Add("type", "assessmentPin");
    
	
	FString ConvertedMap = MapToString(AuthMap);
	SetSessionAuthMechanism_BFL(ConvertedMap);
	Async(EAsyncExecution::ThreadPool, [OnReceivedResponseDelegate]()
	   {
		   int Result = FinalAuthenticate();

		   Async(EAsyncExecution::TaskGraphMainThread, [Result, OnReceivedResponseDelegate]()
		   {
		   		OnReceivedResponseDelegate.ExecuteIfBound(Result);
			   if (Result == 0)
			   {
				   UE_LOG(LogTemp, Log, TEXT("Authentication succeeded!"));
			   		// TODO add callback
			   }
			   else
			   {
				   UE_LOG(LogTemp, Error, TEXT("Authentication failed ---> %d!"), Result);
			   		// TODO add callback
			   }
		   });
	   });
}

TMap<FString, FString> UAbxrBlueprintLibrary::StringToMap(const FString& InputString)
{
	TMap<FString, FString> Dict;
        
	TArray<FString> Pairs;
	InputString.ParseIntoArray(Pairs, TEXT(","), true);

	for (const FString& Pair : Pairs)
	{
		FString TrimmedPair = Pair.TrimStartAndEnd();
		if (!TrimmedPair.IsEmpty())
		{
			FString Key, Value;
			if (TrimmedPair.Split(TEXT("="), &Key, &Value))
				Dict.Add(Key, Value);
			else
				Dict.Add(TrimmedPair, TEXT(""));
		}
	}
	return Dict;
}

FString UAbxrBlueprintLibrary::MapToString(TMap<FString, FString> InputMap)
{
	FString Result;

	for (const TPair<FString, FString>& Pair : InputMap)
	{
		if (!Result.IsEmpty())
		{
			Result += TEXT(",");
		}
		Result += Pair.Key + TEXT("=") + Pair.Value;
	}

	return Result;
}

int UAbxrBlueprintLibrary::FinalAuthenticate_BFL()
{
	return FinalAuthenticate();
}

int UAbxrBlueprintLibrary::ReAuthenticate_BFL(const bool bObtainAuthSecret)
{
	return ReAuthenticate(bObtainAuthSecret);
}

int UAbxrBlueprintLibrary::ForceSendUnsentSynchronous_BFL()
{
	return ForceSendUnsentSynchronous();
}

void UAbxrBlueprintLibrary::CaptureTimeStamp_BFL()
{
	CaptureTimeStamp();
}

void UAbxrBlueprintLibrary::UnCaptureTimeStamp_BFL()
{
	UnCaptureTimeStamp();
}

int UAbxrBlueprintLibrary::LogDebugSynchronous_BFL(const FString szText, const FString szdictMeta)
{
	return LogDebugSynchronous(FStringToChar16Ptr(szText), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::LogDebug_BFL(const FString szText, const FString szdictMeta)
{
	return LogDebug(FStringToChar16Ptr(szText), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::LogInfoSynchronous_BFL(const FString szText, const FString szdictMeta)
{
	return LogInfo(FStringToChar16Ptr(szText), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::LogInfo_BFL(const FString szText, const FString szdictMeta)
{
	return LogInfo(FStringToChar16Ptr(szText), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::LogWarnSynchronous_BFL(const FString szText, const FString szdictMeta)
{
	return LogWarnSynchronous(FStringToChar16Ptr(szText), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::LogWarn_BFL(const FString szText, const FString szdictMeta)
{
	return LogWarn(FStringToChar16Ptr(szText), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::LogErrorSynchronous_BFL(const FString szText, const FString szdictMeta)
{
	return LogError(FStringToChar16Ptr(szText), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::LogError_BFL(const FString szText, const FString szdictMeta)
{
	return LogError(FStringToChar16Ptr(szText), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::LogCriticalSynchronous_BFL(const FString szText, const FString szdictMeta)
{
	return LogCritical(FStringToChar16Ptr(szText), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::LogCritical_BFL(const FString szText, const FString szdictMeta)
{
	return LogCritical(FStringToChar16Ptr(szText), FStringToChar16Ptr(szdictMeta));
}

// ---

int UAbxrBlueprintLibrary::EventSynchronous_BFL(const FString szMessage, const FString szdictMeta)
{
	return EventSynchronous(FStringToChar16Ptr(szMessage), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::Event_BFL(const FString szMessage, const FString szdictMeta)
{
	return Event(FStringToChar16Ptr(szMessage), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::EventAssessmentStart_BFL(const FString szAssessmentName, const FString szdictMeta)
{
	return EventAssessmentStart(FStringToChar16Ptr(szAssessmentName), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::EventAssessmentComplete_BFL(const FString szAssessmentName, const FString szScore,
	const int eResultOptions, const FString szdictMeta)
{
	return EventAssessmentComplete(FStringToChar16Ptr(szAssessmentName), FStringToChar16Ptr(szScore), eResultOptions, FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::EventObjectiveStart_BFL(const FString szObjectiveName, const FString szdictMeta)
{
	return EventObjectiveStart(FStringToChar16Ptr(szObjectiveName), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::EventObjectiveComplete_BFL(const FString szObjectiveName, const FString szScore,
	const int eResultOptions, const FString szdictMeta)
{
	return EventObjectiveComplete(FStringToChar16Ptr(szObjectiveName), FStringToChar16Ptr(szScore), eResultOptions, FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::EventInteractionStart_BFL(const FString szInteractionName, const FString szdictMeta)
{
	return EventInteractionStart(FStringToChar16Ptr(szInteractionName), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::EventInteractionComplete_BFL(const FString szInteractionName, const FString szResult,
	const FString szResultDetails, int eInteractionType, const FString szdictMeta)
{
	return EventInteractionComplete(FStringToChar16Ptr(szInteractionName),
		FStringToChar16Ptr(szResult), FStringToChar16Ptr(szResultDetails),
		eInteractionType, FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::EventLevelStart_BFL(const FString szLevelName, const FString szdictMeta)
{
	return EventLevelStart(FStringToChar16Ptr(szLevelName), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::EventLevelComplete_BFL(const FString szLevelName, const FString szScore,
	const FString szdictMeta)
{
	return  EventLevelComplete(FStringToChar16Ptr(szLevelName), FStringToChar16Ptr(szScore), FStringToChar16Ptr(szdictMeta));
}

// const FString UAbxrBlueprintLibrary::GetDataPath_BFL()
// {
// 	return Char16PtrToFString(get_DataPath());
// }
//
// void UAbxrBlueprintLibrary::SetDataPath_BFL(const FString szDataPath)
// {
// 	set_DataPath(FStringToChar16Ptr(szDataPath));
// }

const FString UAbxrBlueprintLibrary::GetUserId_BFL()
{
	return Char16PtrToFString(get_UserId());
}

void UAbxrBlueprintLibrary::SetUserId_BFL(const FString szUserId)
{
	set_UserId(FStringToChar16Ptr(szUserId));
}

const FString UAbxrBlueprintLibrary::GetSessionAuthMechanism_BFL()
{
	return Char16PtrToFString(get_SessionAuthMechanism());
}

void UAbxrBlueprintLibrary::SetSessionAuthMechanism_BFL(const FString szdictValue)
{
	set_SessionAuthMechanism(FStringToChar16Ptr(szdictValue));
}

const FString UAbxrBlueprintLibrary::GetAppConfigAuthMechanism_BFL()
{
	return Char16PtrToFString(get_AppConfigAuthMechanism());
}

void UAbxrBlueprintLibrary::SetAppConfigAuthMechanism_BFL(const FString szdictValue)
{
	set_AppConfigAuthMechanism(FStringToChar16Ptr(szdictValue));
}

int UAbxrBlueprintLibrary::AddAIProxySynchronous_BFL(const FString szPrompt, const FString szPastMessages,
                                                    const FString szLMMProvider)
{
	return AddAIProxySynchronous(FStringToChar16Ptr(szPrompt), FStringToChar16Ptr(szPastMessages), FStringToChar16Ptr(szLMMProvider));
}

int UAbxrBlueprintLibrary::AddAIProxy_BFL(const FString szPrompt, const FString szPastMessages,
	const FString szLMMProvider)
{
	return AddAIProxy(FStringToChar16Ptr(szPrompt), FStringToChar16Ptr(szPastMessages), FStringToChar16Ptr(szLMMProvider));
}

int UAbxrBlueprintLibrary::AddTelemetryEntrySynchronous_BFL(const FString szName, const FString szdictMeta)
{
	return AddTelemetryEntrySynchronous(FStringToChar16Ptr(szName), FStringToChar16Ptr(szdictMeta));
}

int UAbxrBlueprintLibrary::AddTelemetryEntry_BFL(const FString szName, const FString szdictMeta)
{
	return AddTelemetryEntry(FStringToChar16Ptr(szName), FStringToChar16Ptr(szdictMeta));
}

bool UAbxrBlueprintLibrary::PlatformIsWindows_BFL()
{
	return PlatformIsWindows();
}

FString UAbxrBlueprintLibrary::GetApiToken_BFL()
{
	return Char16PtrToFString(get_ApiToken());
}

void UAbxrBlueprintLibrary::SetApiToken_BFL(const FString szApiToken)
{
	set_ApiToken(FStringToChar16Ptr(szApiToken));
}

FString UAbxrBlueprintLibrary::GetApiSecret_BFL()
{
	return Char16PtrToFString(get_ApiSecret());
}

void UAbxrBlueprintLibrary::SetApiSecret_BFL(const FString szApiSecret)
{
	set_ApiSecret(FStringToChar16Ptr(szApiSecret));
}

FString UAbxrBlueprintLibrary::GetAppID_BFL()
{
	return Char16PtrToFString(get_AppID());
}

void UAbxrBlueprintLibrary::SetAppID_BFL(const FString szAppID)
{
	set_AppID(FStringToChar16Ptr(szAppID));
}

FString UAbxrBlueprintLibrary::GetOrgID_BFL()
{
	return Char16PtrToFString(get_OrgID());
}

void UAbxrBlueprintLibrary::SetOrgID_BFL(const FString szOrgID)
{
	set_OrgID(FStringToChar16Ptr(szOrgID));
}

bool UAbxrBlueprintLibrary::TokenExpirationImminent_BFL()
{
	return TokenExpirationImminent();
}

int UAbxrBlueprintLibrary::GetPartner_BFL()
{
	return get_Partner();
}

void UAbxrBlueprintLibrary::SetPartner_BFL(const int ePartner)
{
	set_Partner(ePartner);
}

FString UAbxrBlueprintLibrary::GetOsVersion_BFL()
{
	return Char16PtrToFString(get_OsVersion());
}

void UAbxrBlueprintLibrary::SetOsVersion_BFL(const FString szOsVersion)
{
	set_OsVersion(FStringToChar16Ptr(szOsVersion));
}

FString UAbxrBlueprintLibrary::GetIpAddress_BFL()
{
	return Char16PtrToFString(get_IpAddress());
}

void UAbxrBlueprintLibrary::SetIpAddress_BFL(const FString szIpAddress)
{
	set_IpAddress(FStringToChar16Ptr(szIpAddress));
}

FString UAbxrBlueprintLibrary::GetXrdmVersion_BFL()
{
	return Char16PtrToFString(get_XrdmVersion());
}

void UAbxrBlueprintLibrary::SetXrdmVersion_BFL(const FString szXrdmVersion)
{
	set_XrdmVersion(FStringToChar16Ptr(szXrdmVersion));
}

FString UAbxrBlueprintLibrary::GetAppVersion_BFL()
{
	return Char16PtrToFString(get_AppVersion());
}

void UAbxrBlueprintLibrary::SetAppVersion_BFL(const FString szAppVersion)
{
	set_AppVersion(FStringToChar16Ptr(szAppVersion));
}

FString UAbxrBlueprintLibrary::GetUnrealVersion_BFL()
{
	return FString();
}

void UAbxrBlueprintLibrary::SetUnrealVersion_BFL(const FString szUnityVersion)
{
}

FString UAbxrBlueprintLibrary::GetDeviceModel_BFL()
{
	return Char16PtrToFString(get_DeviceModel());
}

void UAbxrBlueprintLibrary::SetDeviceModel_BFL(const FString szDeviceModel)
{
	set_DeviceModel(FStringToChar16Ptr(szDeviceModel));
}

FString UAbxrBlueprintLibrary::GetTags_BFL()
{
	return Char16PtrToFString(get_Tags());
}

void UAbxrBlueprintLibrary::SetTags_BFL(const FString szlszTags)
{
	set_Tags(FStringToChar16Ptr(szlszTags));
}

FString UAbxrBlueprintLibrary::GetGeoLocation_BFL()
{
	return Char16PtrToFString(get_GeoLocation());
}

void UAbxrBlueprintLibrary::SetGeoLocation_BFL(const FString szdictGeoLocation)
{
	set_GeoLocation(FStringToChar16Ptr(szdictGeoLocation));
}

FString UAbxrBlueprintLibrary::StorageGetDefaultEntryAsString_BFL()
{
	return Char16PtrToFString(StorageGetDefaultEntryAsString());
}

FString UAbxrBlueprintLibrary::StorageGetEntryAsString_BFL(const FString wszName)
{
	return Char16PtrToFString(StorageGetEntryAsString(FStringToChar16Ptr(wszName)));
}

int UAbxrBlueprintLibrary::StorageSetDefaultEntryFromString_BFL(const FString wszStorageEntry, const bool bKeepLatest,
	const FString wszOrigin, const bool bSessionData)
{
	return StorageSetDefaultEntryFromString(FStringToChar16Ptr(wszStorageEntry), bKeepLatest,
											FStringToChar16Ptr(wszOrigin), bSessionData);
}

int UAbxrBlueprintLibrary::StorageSetEntryFromString_BFL(const FString wszName, const FString wszStorageEntry,
	const bool bKeepLatest, const FString wszOrigin, const bool bSessionData)
{
	return StorageSetEntryFromString(FStringToChar16Ptr(wszName), FStringToChar16Ptr(wszStorageEntry),
		bKeepLatest, FStringToChar16Ptr(wszOrigin), bSessionData);
}

int UAbxrBlueprintLibrary::StorageRemoveDefaultEntry_BFL()
{
	return StorageRemoveDefaultEntry();
}

int UAbxrBlueprintLibrary::StorageRemoveEntry_BFL(const FString wszName)
{
	return StorageRemoveEntry(FStringToChar16Ptr(wszName));
}

int UAbxrBlueprintLibrary::StorageRemoveMultipleEntries_BFL(const bool bSessionOnly)
{
	return StorageRemoveMultipleEntries(bSessionOnly);
}

FString UAbxrBlueprintLibrary::GetRestUrl_BFL()
{
	return Char16PtrToFString(get_RestUrl());
}

void UAbxrBlueprintLibrary::SetRestUrl_BFL(const FString szValue)
{
	set_RestUrl(FStringToChar16Ptr(szValue));
}

int UAbxrBlueprintLibrary::GetSendRetriesOnFailure_BFL()
{
	return get_SendRetriesOnFailure();
}

void UAbxrBlueprintLibrary::SetSendRetriesOnFailure_BFL(int nValue)
{
	set_SendRetriesOnFailure(nValue);
	
}

double UAbxrBlueprintLibrary::GetSendRetryInterval_BFL()
{
	return get_SendRetryInterval();
}

void UAbxrBlueprintLibrary::SetSendRetryInterval_BFL(double tsValue)
{
	set_SendRetryInterval(tsValue);
}

double UAbxrBlueprintLibrary::GetSendNextBatchWait_BFL()
{
	return get_SendNextBatchWait();
}

void UAbxrBlueprintLibrary::SetSendNextBatchWait_BFL(double tsValue)
{
	set_SendNextBatchWait(tsValue);
}

double UAbxrBlueprintLibrary::GetStragglerTimeout_BFL()
{
	return get_StragglerTimeout();
}

void UAbxrBlueprintLibrary::SetStragglerTimeout_BFL(double tsValue)
{
	set_StragglerTimeout(tsValue);
}

int UAbxrBlueprintLibrary::GetEventsPerSendAttempt_BFL()
{
	return get_EventsPerSendAttempt();
}

void UAbxrBlueprintLibrary::SetEventsPerSendAttempt_BFL(int nValue)
{
	set_EventsPerSendAttempt(nValue);
}

int UAbxrBlueprintLibrary::GetLogsPerSendAttempt_BFL()
{
	return get_LogsPerSendAttempt();
}

void UAbxrBlueprintLibrary::SetLogsPerSendAttempt_BFL(int nValue)
{
	set_LogsPerSendAttempt(nValue);
}

int UAbxrBlueprintLibrary::GetTelemetryEntriesPerSendAttempt_BFL()
{
	return get_TelemetryEntriesPerSendAttempt();
}

void UAbxrBlueprintLibrary::SetTelemetryEntriesPerSendAttempt_BFL(int nValue)
{
	set_TelemetryEntriesPerSendAttempt(nValue);
}

int UAbxrBlueprintLibrary::GetStorageEntriesPerSendAttempt_BFL()
{
	return get_StorageEntriesPerSendAttempt();
}

void UAbxrBlueprintLibrary::SetStorageEntriesPerSendAttempt_BFL(int nValue)
{
	set_StorageEntriesPerSendAttempt(nValue);
}

double UAbxrBlueprintLibrary::GetPruneSentItemsOlderThan_BFL()
{
	return get_PruneSentItemsOlderThan();
}

void UAbxrBlueprintLibrary::SetPruneSentItemsOlderThan_BFL(double tsValue)
{
	set_PruneSentItemsOlderThan(tsValue);
}

int UAbxrBlueprintLibrary::GetMaximumCachedItems_BFL()
{
	return get_MaximumCachedItems();
}

void UAbxrBlueprintLibrary::SetMaximumCachedItems_BFL(int nValue)
{
	set_MaximumCachedItems(nValue);
}

bool UAbxrBlueprintLibrary::GetRetainLocalAfterSent_BFL()
{
	return get_RetainLocalAfterSent();
}

void UAbxrBlueprintLibrary::SetRetainLocalAfterSent_BFL(bool bValue)
{
	set_RetainLocalAfterSent(bValue);
}

bool UAbxrBlueprintLibrary::GetReAuthenticateBeforeTokenExpires_BFL()
{
	return get_ReAuthenticateBeforeTokenExpires();
}

void UAbxrBlueprintLibrary::SetReAuthenticateBeforeTokenExpires_BFL(bool bValue)
{
	return set_ReAuthenticateBeforeTokenExpires(bValue);
}

bool UAbxrBlueprintLibrary::GetUseDatabase_BFL()
{
	return get_UseDatabase();
}

void UAbxrBlueprintLibrary::SetUseDatabase_BFL(bool bValue)
{
	set_UseDatabase(bValue);
}

bool UAbxrBlueprintLibrary::ReadConfig_BFL()
{
	return ReadConfig();
}

bool UAbxrBlueprintLibrary::GetAuthSecretCSharp_BFL()
{
	return GetAuthSecretCSharp();
}

void UAbxrBlueprintLibrary::SetGetAuthSecretCallbackRet_BFL(const FString szAuthSecret)
{
	SetGetAuthSecretCallbackRet(FStringToChar16Ptr(szAuthSecret));
}

void UAbxrBlueprintLibrary::SetServingCSharp_BFL(const bool bServingCSharp)
{
	SetServingCSharp(bServingCSharp);
}

bool UAbxrBlueprintLibrary::GetNextDiagnosticString_BFL(FString& pbstrString)
{
	char16_t* char16Str = nullptr;

	bool result = GetNextDiagnosticString(&char16Str);

	if (result && char16Str != nullptr) 
		pbstrString = FString(reinterpret_cast<const TCHAR*>(char16Str));
	else
		pbstrString = FString();

	return result;

}

uint8 UAbxrBlueprintLibrary::HTTPGet_BFL(const FString bstrUrl, FString& pbstrResponse)
{
	char16_t* char16Str = nullptr;
	auto result = HTTPGet(FStringToChar16Ptr(bstrUrl), &char16Str);
	if (char16Str != nullptr) 
		pbstrResponse = FString(reinterpret_cast<const TCHAR*>(char16Str));
	return 0;
}

uint8 UAbxrBlueprintLibrary::HTTPPost_BFL(const FString bstrUrl, FString& pbstrResponse)
{
	char16_t* char16Str = nullptr;
	auto result = HTTPPost(FStringToChar16Ptr(bstrUrl), &char16Str);
	if (char16Str != nullptr) 
		pbstrResponse = FString(reinterpret_cast<const TCHAR*>(char16Str));
	return 0;
}

int UAbxrBlueprintLibrary::AbxrLibAnalyticsTestsInterop_BFL(const FString bstrCommandLine)
{
	return AbxrLibAnalyticsTestsInterop(FStringToChar16Ptr(bstrCommandLine));
}

// FString UAbxrBlueprintLibrary::TestGetAuthSecretCallback_BFL()
// {
// 	return Char16PtrToFString(TestGetAuthSecretCallback());
// }
