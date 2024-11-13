// Fill out your copyright notice in the Description page of Project Settings.


#include "IXRBlueprintLibrary.h"
#include "Interface.h"
#include "iXRDeveloperSettings.h"


char16_t* FStringToChar16Ptr(const FString& UnrealString) {
	TArray<TCHAR> CharArray = UnrealString.GetCharArray();
	char16_t* Char16Ptr = reinterpret_cast<char16_t*>(CharArray.GetData());
	return Char16Ptr;
}

FString Char16PtrToFString(const char16_t* Char16Ptr) {
	const TCHAR* TCHARPtr = reinterpret_cast<const TCHAR*>(Char16Ptr);
	return FString(TCHARPtr);
}

uint32_t IntToUint32(const int UnrealInt) { return static_cast<uint32_t>(UnrealInt); }

void UIXRBlueprintLibrary::StartIXRLib_BFL()
{
	iXRLibInitStart();
	SetServingCSharp(true);
	UE_LOG(LogTemp, Warning, TEXT("FORCE Send ---> %d"), ForceSendUnsentSynchronous());
	const char16_t* appID =  reinterpret_cast<const char16_t*>(*UiXRDeveloperSettings::GetiXRConfig()->appID);
	const char16_t* orgID =  reinterpret_cast<const char16_t*>(*UiXRDeveloperSettings::GetiXRConfig()->orgID);
	const char16_t* deviceID =  reinterpret_cast<const char16_t*>(*FGuid::NewGuid().ToString());
	const char16_t* authSecret =  reinterpret_cast<const char16_t*>(*UiXRDeveloperSettings::GetiXRConfig()->authSecret);
	const char16_t* TestStr =  reinterpret_cast<const char16_t*>(TEXT("iXR lib dll Hello!"));
	int StatusIndex = Authenticate(appID, orgID, deviceID, authSecret, 0);
	UE_LOG(LogTemp, Warning, TEXT("Authenticated = %d"), StatusIndex);
	LogInfo(TestStr);
	LogWarn(TestStr);
	LogError(TestStr);
	LogWarnSynchronous(TestStr);
}

void UIXRBlueprintLibrary::iXRLibInitStart_BFL()
{
}

void UIXRBlueprintLibrary::iXRLibInitEnd_BFL()
{
}

int UIXRBlueprintLibrary::Authenticate_BFL(const FString szAppId, const FString szOrgId, const FString szDeviceId,
	const FString szAuthSecret, const int ePartner)
{
	return Authenticate(FStringToChar16Ptr(szAppId), FStringToChar16Ptr(szOrgId),
						FStringToChar16Ptr(szDeviceId), FStringToChar16Ptr(szAuthSecret), IntToUint32(ePartner));
}

int UIXRBlueprintLibrary::ReAuthenticate_BFL(const bool bObtainAuthSecret)
{
	return ReAuthenticate(bObtainAuthSecret);
}

int UIXRBlueprintLibrary::ForceSendUnsentSynchronous_BFL()
{
	return ForceSendUnsentSynchronous();
}

void UIXRBlueprintLibrary::CaptureTimeStamp_BFL()
{
	CaptureTimeStamp();
}

void UIXRBlueprintLibrary::UnCaptureTimeStamp_BFL()
{
	UnCaptureTimeStamp();
}

int UIXRBlueprintLibrary::LogDebugSynchronous_BFL(const FString szText)
{
	return LogDebugSynchronous(FStringToChar16Ptr(szText));
}

int UIXRBlueprintLibrary::LogDebug_BFL(const FString szText)
{
	return LogDebug(FStringToChar16Ptr(szText));
}

int UIXRBlueprintLibrary::LogInfoSynchronous_BFL(const FString szText)
{
	return LogInfo(FStringToChar16Ptr(szText));
}

int UIXRBlueprintLibrary::LogInfo_BFL(const FString szText)
{
	return LogInfo(FStringToChar16Ptr(szText));
}

int UIXRBlueprintLibrary::LogWarnSynchronous_BFL(const FString szText)
{
	return LogWarnSynchronous(FStringToChar16Ptr(szText));
}

int UIXRBlueprintLibrary::LogWarn_BFL(const FString szText)
{
	return LogWarn(FStringToChar16Ptr(szText));
}

int UIXRBlueprintLibrary::LogErrorSynchronous_BFL(const FString szText)
{
	return LogError(FStringToChar16Ptr(szText));
}

int UIXRBlueprintLibrary::LogError_BFL(const FString szText)
{
	return LogError(FStringToChar16Ptr(szText));
}

int UIXRBlueprintLibrary::LogCriticalSynchronous_BFL(const FString szText)
{
	return LogCritical(FStringToChar16Ptr(szText));
}

int UIXRBlueprintLibrary::LogCritical_BFL(const FString szText)
{
	return LogCritical(FStringToChar16Ptr(szText));
}

int UIXRBlueprintLibrary::EventSynchronous_BFL(const FString szMessage, const FString szdictMeta)
{
	return EventSynchronous(FStringToChar16Ptr(szMessage), FStringToChar16Ptr(szdictMeta));
}

int UIXRBlueprintLibrary::Event_BFL(const FString szMessage, const FString szdictMeta)
{
	return Event(FStringToChar16Ptr(szMessage), FStringToChar16Ptr(szdictMeta));
}

int UIXRBlueprintLibrary::AddAIProxySynchronous_BFL(const FString szPrompt, const FString szPastMessages,
	const FString szLMMProvider)
{
	return AddAIProxySynchronous(FStringToChar16Ptr(szPrompt), FStringToChar16Ptr(szPastMessages), FStringToChar16Ptr(szLMMProvider));
}

int UIXRBlueprintLibrary::AddAIProxy_BFL(const FString szPrompt, const FString szPastMessages,
	const FString szLMMProvider)
{
	return AddAIProxy(FStringToChar16Ptr(szPrompt), FStringToChar16Ptr(szPastMessages), FStringToChar16Ptr(szLMMProvider));
}

int UIXRBlueprintLibrary::AddTelemetryEntrySynchronous_BFL(const FString szName, const FString szdictData)
{
	return AddTelemetryEntrySynchronous(FStringToChar16Ptr(szName), FStringToChar16Ptr(szdictData));
}

int UIXRBlueprintLibrary::AddTelemetryEntry_BFL(const FString szName, const FString szdictData)
{
	return AddTelemetryEntry(FStringToChar16Ptr(szName), FStringToChar16Ptr(szdictData));
}

bool UIXRBlueprintLibrary::PlatformIsWindows_BFL()
{
	return PlatformIsWindows();
}

FString UIXRBlueprintLibrary::GetApiToken_BFL()
{
	return Char16PtrToFString(get_ApiToken());
}

void UIXRBlueprintLibrary::SetApiToken_BFL(const FString szApiToken)
{
	set_ApiToken(FStringToChar16Ptr(szApiToken));
}

FString UIXRBlueprintLibrary::GetApiSecret_BFL()
{
	return Char16PtrToFString(get_ApiSecret());
}

void UIXRBlueprintLibrary::SetApiSecret_BFL(const FString szApiSecret)
{
	set_ApiSecret(FStringToChar16Ptr(szApiSecret));
}

FString UIXRBlueprintLibrary::GetAppID_BFL()
{
	return Char16PtrToFString(get_AppID());
}

void UIXRBlueprintLibrary::SetAppID_BFL(const FString szAppID)
{
	set_AppID(FStringToChar16Ptr(szAppID));
}

FString UIXRBlueprintLibrary::GetOrgID_BFL()
{
	return Char16PtrToFString(get_OrgID());
}

void UIXRBlueprintLibrary::SetOrgID_BFL(const FString szOrgID)
{
	set_OrgID(FStringToChar16Ptr(szOrgID));
}

bool UIXRBlueprintLibrary::TokenExpirationImminent_BFL()
{
	return TokenExpirationImminent();
}

int UIXRBlueprintLibrary::GetPartner_BFL()
{
	return get_Partner();
}

void UIXRBlueprintLibrary::SetPartner_BFL(const int ePartner)
{
	set_Partner(ePartner);
}

FString UIXRBlueprintLibrary::GetOsVersion_BFL()
{
	return Char16PtrToFString(get_OsVersion());
}

void UIXRBlueprintLibrary::SetOsVersion_BFL(const FString szOsVersion)
{
	set_OsVersion(FStringToChar16Ptr(szOsVersion));
}

FString UIXRBlueprintLibrary::GetIpAddress_BFL()
{
	return Char16PtrToFString(get_IpAddress());
}

void UIXRBlueprintLibrary::SetIpAddress_BFL(const FString szIpAddress)
{
	set_IpAddress(FStringToChar16Ptr(szIpAddress));
}

FString UIXRBlueprintLibrary::GetXrdmVersion_BFL()
{
	return Char16PtrToFString(get_XrdmVersion());
}

void UIXRBlueprintLibrary::SetXrdmVersion_BFL(const FString szXrdmVersion)
{
	set_XrdmVersion(FStringToChar16Ptr(szXrdmVersion));
}

FString UIXRBlueprintLibrary::GetAppVersion_BFL()
{
	return Char16PtrToFString(get_AppVersion());
}

void UIXRBlueprintLibrary::SetAppVersion_BFL(const FString szAppVersion)
{
	set_AppVersion(FStringToChar16Ptr(szAppVersion));
}

FString UIXRBlueprintLibrary::GetUnrealVersion_BFL()
{
	return FString();
}

void UIXRBlueprintLibrary::SetUnrealVersion_BFL(const FString szUnityVersion)
{
}

FString UIXRBlueprintLibrary::GetDeviceModel_BFL()
{
	return Char16PtrToFString(get_DeviceModel());
}

void UIXRBlueprintLibrary::SetDeviceModel_BFL(const FString szDeviceModel)
{
	set_DeviceModel(FStringToChar16Ptr(szDeviceModel));
}

FString UIXRBlueprintLibrary::GetTags_BFL()
{
	return Char16PtrToFString(get_Tags());
}

void UIXRBlueprintLibrary::SetTags_BFL(const FString szlszTags)
{
	set_Tags(FStringToChar16Ptr(szlszTags));
}

FString UIXRBlueprintLibrary::GetGeoLocation_BFL()
{
	return Char16PtrToFString(get_GeoLocation());
}

void UIXRBlueprintLibrary::SetGeoLocation_BFL(const FString szdictGeoLocation)
{
	set_GeoLocation(FStringToChar16Ptr(szdictGeoLocation));
}

FString UIXRBlueprintLibrary::StorageGetDefaultEntryAsString_BFL()
{
	return Char16PtrToFString(StorageGetDefaultEntryAsString());
}

FString UIXRBlueprintLibrary::StorageGetEntryAsString_BFL(const FString wszName)
{
	return Char16PtrToFString(StorageGetEntryAsString(FStringToChar16Ptr(wszName)));
}

int UIXRBlueprintLibrary::StorageSetDefaultEntryFromString_BFL(const FString wszStorageEntry, const bool bKeepLatest,
	const FString wszOrigin, const bool bSessionData)
{
	return StorageSetDefaultEntryFromString(FStringToChar16Ptr(wszStorageEntry), bKeepLatest,
											FStringToChar16Ptr(wszOrigin), bSessionData);
}

int UIXRBlueprintLibrary::StorageSetEntryFromString_BFL(const FString wszName, const FString wszStorageEntry,
	const bool bKeepLatest, const FString wszOrigin, const bool bSessionData)
{
	return StorageSetEntryFromString(FStringToChar16Ptr(wszName), FStringToChar16Ptr(wszStorageEntry),
		bKeepLatest, FStringToChar16Ptr(wszOrigin), bSessionData);
}

int UIXRBlueprintLibrary::StorageRemoveDefaultEntry_BFL()
{
	return StorageRemoveDefaultEntry();
}

int UIXRBlueprintLibrary::StorageRemoveEntry_BFL(const FString wszName)
{
	return StorageRemoveEntry(FStringToChar16Ptr(wszName));
}

int UIXRBlueprintLibrary::StorageRemoveMultipleEntries_BFL(const bool bSessionOnly)
{
	return StorageRemoveMultipleEntries(bSessionOnly);
}

FString UIXRBlueprintLibrary::GetRestUrl_BFL()
{
	return Char16PtrToFString(get_RestUrl());
}

void UIXRBlueprintLibrary::SetRestUrl_BFL(const FString szValue)
{
	set_RestUrl(FStringToChar16Ptr(szValue));
}

int UIXRBlueprintLibrary::GetSendRetriesOnFailure_BFL()
{
	return get_SendRetriesOnFailure();
}

void UIXRBlueprintLibrary::SetSendRetriesOnFailure_BFL(int nValue)
{
	set_SendRetriesOnFailure(nValue);
}

double UIXRBlueprintLibrary::GetSendRetryInterval_BFL()
{
	return get_SendRetryInterval();
}

void UIXRBlueprintLibrary::SetSendRetryInterval_BFL(double tsValue)
{
	set_SendRetryInterval(tsValue);
}

double UIXRBlueprintLibrary::GetSendNextBatchWait_BFL()
{
	return get_SendNextBatchWait();
}

void UIXRBlueprintLibrary::SetSendNextBatchWait_BFL(double tsValue)
{
	set_SendNextBatchWait(tsValue);
}

double UIXRBlueprintLibrary::GetStragglerTimeout_BFL()
{
	return get_StragglerTimeout();
}

void UIXRBlueprintLibrary::SetStragglerTimeout_BFL(double tsValue)
{
	set_StragglerTimeout(tsValue);
}

int UIXRBlueprintLibrary::GetEventsPerSendAttempt_BFL()
{
	return get_EventsPerSendAttempt();
}

void UIXRBlueprintLibrary::SetEventsPerSendAttempt_BFL(int nValue)
{
	set_EventsPerSendAttempt(nValue);
}

int UIXRBlueprintLibrary::GetLogsPerSendAttempt_BFL()
{
	return get_LogsPerSendAttempt();
}

void UIXRBlueprintLibrary::SetLogsPerSendAttempt_BFL(int nValue)
{
	set_LogsPerSendAttempt(nValue);
}

int UIXRBlueprintLibrary::GetTelemetryEntriesPerSendAttempt_BFL()
{
	return get_TelemetryEntriesPerSendAttempt();
}

void UIXRBlueprintLibrary::SetTelemetryEntriesPerSendAttempt_BFL(int nValue)
{
	set_TelemetryEntriesPerSendAttempt(nValue);
}

int UIXRBlueprintLibrary::GetStorageEntriesPerSendAttempt_BFL()
{
	return get_StorageEntriesPerSendAttempt();
}

void UIXRBlueprintLibrary::SetStorageEntriesPerSendAttempt_BFL(int nValue)
{
	set_StorageEntriesPerSendAttempt(nValue);
}

double UIXRBlueprintLibrary::GetPruneSentItemsOlderThan_BFL()
{
	return get_PruneSentItemsOlderThan();
}

void UIXRBlueprintLibrary::SetPruneSentItemsOlderThan_BFL(double tsValue)
{
	set_PruneSentItemsOlderThan(tsValue);
}

int UIXRBlueprintLibrary::GetMaximumCachedItems_BFL()
{
	return get_MaximumCachedItems();
}

void UIXRBlueprintLibrary::SetMaximumCachedItems_BFL(int nValue)
{
	set_MaximumCachedItems(nValue);
}

bool UIXRBlueprintLibrary::GetRetainLocalAfterSent_BFL()
{
	return get_RetainLocalAfterSent();
}

void UIXRBlueprintLibrary::SetRetainLocalAfterSent_BFL(bool bValue)
{
	set_RetainLocalAfterSent(bValue);
}

bool UIXRBlueprintLibrary::GetReAuthenticateBeforeTokenExpires_BFL()
{
	return get_ReAuthenticateBeforeTokenExpires();
}

void UIXRBlueprintLibrary::SetReAuthenticateBeforeTokenExpires_BFL(bool bValue)
{
	return set_ReAuthenticateBeforeTokenExpires(bValue);
}

bool UIXRBlueprintLibrary::GetUseDatabase_BFL()
{
	return get_UseDatabase();
}

void UIXRBlueprintLibrary::SetUseDatabase_BFL(bool bValue)
{
	set_UseDatabase(bValue);
}

bool UIXRBlueprintLibrary::ReadConfig_BFL()
{
	return ReadConfig();
}

bool UIXRBlueprintLibrary::GetAuthSecretCSharp_BFL()
{
	return GetAuthSecretCSharp();
}

void UIXRBlueprintLibrary::SetGetAuthSecretCallbackRet_BFL(const FString szAuthSecret)
{
	SetGetAuthSecretCallbackRet(FStringToChar16Ptr(szAuthSecret));
}

void UIXRBlueprintLibrary::SetServingCSharp_BFL(const bool bServingCSharp)
{
	SetServingCSharp(bServingCSharp);
}

bool UIXRBlueprintLibrary::GetNextDiagnosticString_BFL(FString& pbstrString)
{
	char16_t* char16Str = nullptr;

	bool result = GetNextDiagnosticString(&char16Str);

	if (result && char16Str != nullptr) 
		pbstrString = FString(reinterpret_cast<const TCHAR*>(char16Str));
	else
		pbstrString = FString();

	return result;

}

// TODO:
uint8 UIXRBlueprintLibrary::HTTPGet_BFL(const FString bstrUrl, FString& pbstrResponse)
{
	char16_t* char16Str = nullptr;
	auto result = HTTPGet(FStringToChar16Ptr(bstrUrl), &char16Str);
	if (char16Str != nullptr) 
		pbstrResponse = FString(reinterpret_cast<const TCHAR*>(char16Str));
	return 0;
}

// TODO:
uint8 UIXRBlueprintLibrary::HTTPPost_BFL(const FString bstrUrl, FString& pbstrResponse)
{
	char16_t* char16Str = nullptr;
	auto result = HTTPPost(FStringToChar16Ptr(bstrUrl), &char16Str);
	if (char16Str != nullptr) 
		pbstrResponse = FString(reinterpret_cast<const TCHAR*>(char16Str));
	return 0;
}

int UIXRBlueprintLibrary::iXRLibAnalyticsTestsInterop_BFL(const FString bstrCommandLine)
{
	return iXRLibAnalyticsTestsInterop(FStringToChar16Ptr(bstrCommandLine));
}

FString UIXRBlueprintLibrary::TestGetAuthSecretCallback_BFL()
{
	return Char16PtrToFString(TestGetAuthSecretCallback());
}
