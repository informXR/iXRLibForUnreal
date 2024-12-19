#pragma once

#ifndef _UNIX
#include <combaseapi.h>
#endif // _UNIX
#include <clocale>
#include <cwchar>
#include <iostream>

// Also in UtilityTypes.h... slightly stinky but Interface.h needs to be kept as agnostic as possible.
#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifdef _UNIX
using BSTR = char16_t*;
#endif

constexpr char16_t* str16cpy(char16_t* szDest, const char16_t* szSource)
{
	char16_t	*szTemp = szDest;

	while ((*szTemp++ = *szSource++) != 0)
	{
	}
	return szDest;
}

inline intptr_t str16len(const char16_t* sz)
{
	intptr_t	n;

	for (n = 0; *sz; n++, sz++)
	{
	}
	return n;
}

#ifdef _UNIX
#define DLLEXPORT
#else
#define DLLEXPORT __declspec(dllexport)
#endif // _UNIX

// Copied from curl.h... same stinkiness.  Notice it is actually CURLCode vs CURLcode... need to cast when using this.
enum class CURLCode
{
	CURLE_OK = 0,
	CURLE_UNSUPPORTED_PROTOCOL,    /* 1 */
	CURLE_FAILED_INIT,             /* 2 */
	CURLE_URL_MALFORMAT,           /* 3 */
	CURLE_NOT_BUILT_IN,            /* 4 - [was obsoleted in August 2007 for
	7.17.0, reused in April 2011 for 7.21.5] */
	CURLE_COULDNT_RESOLVE_PROXY,   /* 5 */
	CURLE_COULDNT_RESOLVE_HOST,    /* 6 */
	CURLE_COULDNT_CONNECT,         /* 7 */
	CURLE_WEIRD_SERVER_REPLY,      /* 8 */
	CURLE_REMOTE_ACCESS_DENIED,    /* 9 a service was denied by the server
	due to lack of access - when login fails
	this is not returned. */
	CURLE_FTP_ACCEPT_FAILED,       /* 10 - [was obsoleted in April 2006 for
	7.15.4, reused in Dec 2011 for 7.24.0]*/
	CURLE_FTP_WEIRD_PASS_REPLY,    /* 11 */
	CURLE_FTP_ACCEPT_TIMEOUT,      /* 12 - timeout occurred accepting server
	[was obsoleted in August 2007 for 7.17.0,
	reused in Dec 2011 for 7.24.0]*/
	CURLE_FTP_WEIRD_PASV_REPLY,    /* 13 */
	CURLE_FTP_WEIRD_227_FORMAT,    /* 14 */
	CURLE_FTP_CANT_GET_HOST,       /* 15 */
	CURLE_HTTP2,                   /* 16 - A problem in the http2 framing layer.
	[was obsoleted in August 2007 for 7.17.0,
	reused in July 2014 for 7.38.0] */
	CURLE_FTP_COULDNT_SET_TYPE,    /* 17 */
	CURLE_PARTIAL_FILE,            /* 18 */
	CURLE_FTP_COULDNT_RETR_FILE,   /* 19 */
	CURLE_OBSOLETE20,              /* 20 - NOT USED */
	CURLE_QUOTE_ERROR,             /* 21 - quote command failure */
	CURLE_HTTP_RETURNED_ERROR,     /* 22 */
	CURLE_WRITE_ERROR,             /* 23 */
	CURLE_OBSOLETE24,              /* 24 - NOT USED */
	CURLE_UPLOAD_FAILED,           /* 25 - failed upload "command" */
	CURLE_READ_ERROR,              /* 26 - couldn't open/read from file */
	CURLE_OUT_OF_MEMORY,           /* 27 */
	CURLE_OPERATION_TIMEDOUT,      /* 28 - the timeout time was reached */
	CURLE_OBSOLETE29,              /* 29 - NOT USED */
	CURLE_FTP_PORT_FAILED,         /* 30 - FTP PORT operation failed */
	CURLE_FTP_COULDNT_USE_REST,    /* 31 - the REST command failed */
	CURLE_OBSOLETE32,              /* 32 - NOT USED */
	CURLE_RANGE_ERROR,             /* 33 - RANGE "command" didn't work */
	CURLE_HTTP_POST_ERROR,         /* 34 */
	CURLE_SSL_CONNECT_ERROR,       /* 35 - wrong when connecting with SSL */
	CURLE_BAD_DOWNLOAD_RESUME,     /* 36 - couldn't resume download */
	CURLE_FILE_COULDNT_READ_FILE,  /* 37 */
	CURLE_LDAP_CANNOT_BIND,        /* 38 */
	CURLE_LDAP_SEARCH_FAILED,      /* 39 */
	CURLE_OBSOLETE40,              /* 40 - NOT USED */
	CURLE_FUNCTION_NOT_FOUND,      /* 41 - NOT USED starting with 7.53.0 */
	CURLE_ABORTED_BY_CALLBACK,     /* 42 */
	CURLE_BAD_FUNCTION_ARGUMENT,   /* 43 */
	CURLE_OBSOLETE44,              /* 44 - NOT USED */
	CURLE_INTERFACE_FAILED,        /* 45 - CURLOPT_INTERFACE failed */
	CURLE_OBSOLETE46,              /* 46 - NOT USED */
	CURLE_TOO_MANY_REDIRECTS,      /* 47 - catch endless re-direct loops */
	CURLE_UNKNOWN_OPTION,          /* 48 - User specified an unknown option */
	CURLE_SETOPT_OPTION_SYNTAX,    /* 49 - Malformed setopt option */
	CURLE_OBSOLETE50,              /* 50 - NOT USED */
	CURLE_OBSOLETE51,              /* 51 - NOT USED */
	CURLE_GOT_NOTHING,             /* 52 - when this is a specific error */
	CURLE_SSL_ENGINE_NOTFOUND,     /* 53 - SSL crypto engine not found */
	CURLE_SSL_ENGINE_SETFAILED,    /* 54 - can not set SSL crypto engine as
	default */
	CURLE_SEND_ERROR,              /* 55 - failed sending network data */
	CURLE_RECV_ERROR,              /* 56 - failure in receiving network data */
	CURLE_OBSOLETE57,              /* 57 - NOT IN USE */
	CURLE_SSL_CERTPROBLEM,         /* 58 - problem with the local certificate */
	CURLE_SSL_CIPHER,              /* 59 - couldn't use specified cipher */
	CURLE_PEER_FAILED_VERIFICATION, /* 60 - peer's certificate or fingerprint
	wasn't verified fine */
	CURLE_BAD_CONTENT_ENCODING,    /* 61 - Unrecognized/bad encoding */
	CURLE_OBSOLETE62,              /* 62 - NOT IN USE since 7.82.0 */
	CURLE_FILESIZE_EXCEEDED,       /* 63 - Maximum file size exceeded */
	CURLE_USE_SSL_FAILED,          /* 64 - Requested FTP SSL level failed */
	CURLE_SEND_FAIL_REWIND,        /* 65 - Sending the data requires a rewind
	that failed */
	CURLE_SSL_ENGINE_INITFAILED,   /* 66 - failed to initialise ENGINE */
	CURLE_LOGIN_DENIED,            /* 67 - user, password or similar was not
	accepted and we failed to login */
	CURLE_TFTP_NOTFOUND,           /* 68 - file not found on server */
	CURLE_TFTP_PERM,               /* 69 - permission problem on server */
	CURLE_REMOTE_DISK_FULL,        /* 70 - out of disk space on server */
	CURLE_TFTP_ILLEGAL,            /* 71 - Illegal TFTP operation */
	CURLE_TFTP_UNKNOWNID,          /* 72 - Unknown transfer ID */
	CURLE_REMOTE_FILE_EXISTS,      /* 73 - File already exists */
	CURLE_TFTP_NOSUCHUSER,         /* 74 - No such user */
	CURLE_OBSOLETE75,              /* 75 - NOT IN USE since 7.82.0 */
	CURLE_OBSOLETE76,              /* 76 - NOT IN USE since 7.82.0 */
	CURLE_SSL_CACERT_BADFILE,      /* 77 - could not load CACERT file, missing
	or wrong format */
	CURLE_REMOTE_FILE_NOT_FOUND,   /* 78 - remote file not found */
	CURLE_SSH,                     /* 79 - error from the SSH layer, somewhat
	generic so the error message will be of
	interest when this has happened */

	CURLE_SSL_SHUTDOWN_FAILED,     /* 80 - Failed to shut down the SSL
	connection */
	CURLE_AGAIN,                   /* 81 - socket is not ready for send/recv,
	wait till it's ready and try again (Added
	in 7.18.2) */
	CURLE_SSL_CRL_BADFILE,         /* 82 - could not load CRL file, missing or
	wrong format (Added in 7.19.0) */
	CURLE_SSL_ISSUER_ERROR,        /* 83 - Issuer check failed.  (Added in
	7.19.0) */
	CURLE_FTP_PRET_FAILED,         /* 84 - a PRET command failed */
	CURLE_RTSP_CSEQ_ERROR,         /* 85 - mismatch of RTSP CSeq numbers */
	CURLE_RTSP_SESSION_ERROR,      /* 86 - mismatch of RTSP Session Ids */
	CURLE_FTP_BAD_FILE_LIST,       /* 87 - unable to parse FTP file list */
	CURLE_CHUNK_FAILED,            /* 88 - chunk callback reported error */
	CURLE_NO_CONNECTION_AVAILABLE, /* 89 - No connection available, the
	session will be queued */
	CURLE_SSL_PINNEDPUBKEYNOTMATCH, /* 90 - specified pinned public key did not
	match */
	CURLE_SSL_INVALIDCERTSTATUS,   /* 91 - invalid certificate status */
	CURLE_HTTP2_STREAM,            /* 92 - stream error in HTTP/2 framing layer
	*/
	CURLE_RECURSIVE_API_CALL,      /* 93 - an api function was called from
	inside a callback */
	CURLE_AUTH_ERROR,              /* 94 - an authentication function returned an
	error */
	CURLE_HTTP3,                   /* 95 - An HTTP/3 layer problem */
	CURLE_QUIC_CONNECT_ERROR,      /* 96 - QUIC connection error */
	CURLE_PROXY,                   /* 97 - proxy handshake error */
	CURLE_SSL_CLIENTCERT,          /* 98 - client-side certificate required */
	CURLE_UNRECOVERABLE_POLL,      /* 99 - poll/select returned fatal error */
	CURL_LAST /* never use! */
};

using CSharpTimeSpan = double;
using CSharpDateTime = time_t;

extern "C" DLLEXPORT void FreePtr(char16_t* ptr);
// --- API code.
extern "C" DLLEXPORT void iXRLibInitStart();
extern "C" DLLEXPORT void iXRLibInitEnd();
// ---
extern "C" DLLEXPORT uint32_t Authenticate(const char16_t* szAppId, const char16_t* szOrgId, const char16_t* szDeviceId, const char16_t* szAuthSecret, const uint32_t ePartner);
extern "C" DLLEXPORT uint32_t FinalAuthenticate();
extern "C" DLLEXPORT uint32_t ReAuthenticate(const bool bObtainAuthSecret);
extern "C" DLLEXPORT uint32_t ForceSendUnsentSynchronous();
// ---
extern "C" DLLEXPORT void CaptureTimeStamp();
extern "C" DLLEXPORT void UnCaptureTimeStamp();
// ---
extern "C" DLLEXPORT uint32_t LogDebugSynchronous(const char16_t* szText);
extern "C" DLLEXPORT uint32_t LogDebug(const char16_t* szText);
extern "C" DLLEXPORT uint32_t LogInfoSynchronous(const char16_t* szText);
extern "C" DLLEXPORT uint32_t LogInfo(const char16_t* szText);
extern "C" DLLEXPORT uint32_t LogWarnSynchronous(const char16_t* szText);
extern "C" DLLEXPORT uint32_t LogWarn(const char16_t* szText);
extern "C" DLLEXPORT uint32_t LogErrorSynchronous(const char16_t* szText);
extern "C" DLLEXPORT uint32_t LogError(const char16_t* szText);
extern "C" DLLEXPORT uint32_t LogCriticalSynchronous(const char16_t* szText);
extern "C" DLLEXPORT uint32_t LogCritical(const char16_t* szText);
// ---
extern "C" DLLEXPORT uint32_t EventSynchronous(const char16_t* szMessage, const char16_t* szdictMeta);
extern "C" DLLEXPORT uint32_t Event(const char16_t* szMessage, const char16_t* szdictMeta);
// --- Convenient wrappers for particular forms of events.
extern "C" DLLEXPORT uint32_t EventAssessmentStart(const char16_t* szAssessmentName, const char16_t* szdictMeta);
extern "C" DLLEXPORT uint32_t EventAssessmentComplete(const char16_t* szAssessmentName, const char16_t* szScore, const uint32_t eResultOptions, const char16_t* szdictMeta);
// ---
extern "C" DLLEXPORT uint32_t EventObjectiveStart(const char16_t* szObjectiveName, const char16_t* szdictMeta);
extern "C" DLLEXPORT uint32_t EventObjectiveComplete(const char16_t* szObjectiveName, const char16_t* szScore, const uint32_t eResultOptions, const char16_t* szdictMeta);
// ---
extern "C" DLLEXPORT uint32_t EventInteractionStart(const char16_t* szInteractionName, const char16_t* szdictMeta);
extern "C" DLLEXPORT uint32_t EventInteractionComplete(const char16_t* szInteractionName, const char16_t* szResult, const char16_t* szResultDetails, uint32_t eInteractionType, const char16_t* szdictMeta);
// ---
extern "C" DLLEXPORT uint32_t EventLevelStart(const char16_t* szLevelName, const char16_t* szdictMeta);
extern "C" DLLEXPORT uint32_t EventLevelComplete(const char16_t* szLevelName, const char16_t* szScore, const char16_t* szdictMeta);
// ---
extern "C" DLLEXPORT uint32_t AddAIProxySynchronous(const char16_t* szPrompt, const char16_t* szPastMessages, const char16_t* szLMMProvider);
extern "C" DLLEXPORT uint32_t AddAIProxy(const char16_t* szPrompt, const char16_t* szPastMessages, const char16_t* szLMMProvider);
// ---
extern "C" DLLEXPORT uint32_t AddTelemetryEntrySynchronous(const char16_t* szName, const char16_t* szdictData);
extern "C" DLLEXPORT uint32_t AddTelemetryEntry(const char16_t* szName, const char16_t* szdictData);
// ---
extern "C" DLLEXPORT bool PlatformIsWindows();
// --- Authentication fields.
extern "C" DLLEXPORT const char16_t* get_ApiToken();
extern "C" DLLEXPORT void set_ApiToken(const char16_t* szApiToken);
// ---
extern "C" DLLEXPORT const char16_t* get_ApiSecret();
extern "C" DLLEXPORT void set_ApiSecret(const char16_t* szApiSecret);
// ---
extern "C" DLLEXPORT const char16_t* get_AppID();
extern "C" DLLEXPORT void set_AppID(const char16_t* szAppID);
// ---
extern "C" DLLEXPORT const char16_t* get_OrgID();
extern "C" DLLEXPORT void set_OrgID(const char16_t* szOrgID);
// ---
extern "C" DLLEXPORT CSharpDateTime get_TokenExpiration();
extern "C" DLLEXPORT void set_TokenExpiration(const CSharpDateTime dtTokenExpiration);
// ---
extern "C" DLLEXPORT bool TokenExpirationImminent();
// ---
extern "C" DLLEXPORT const uint32_t get_Partner();
extern "C" DLLEXPORT void set_Partner(const uint32_t ePartner);
// --- Environment/session globals that get sent with the auth payload in Authenticate() functions.
extern "C" DLLEXPORT const char16_t* get_OsVersion();
extern "C" DLLEXPORT void set_OsVersion(const char16_t* szOsVersion);
// ---
extern "C" DLLEXPORT const char16_t* get_IpAddress();
extern "C" DLLEXPORT void set_IpAddress(const char16_t* szIpAddress);
// ---
extern "C" DLLEXPORT const char16_t* get_XrdmVersion();
extern "C" DLLEXPORT void set_XrdmVersion(const char16_t* szXrdmVersion);
// ---
extern "C" DLLEXPORT const char16_t* get_AppVersion();
extern "C" DLLEXPORT void set_AppVersion(const char16_t* szAppVersion);
// ---
extern "C" DLLEXPORT const char16_t* get_UnityVersion();
extern "C" DLLEXPORT void set_UnityVersion(const char16_t* szUnityVersion);
// ---
extern "C" DLLEXPORT const char16_t* get_DataPath();
extern "C" DLLEXPORT void set_DataPath(const char16_t* szDataPath);
// ---
extern "C" DLLEXPORT const char16_t* get_DeviceModel();
extern "C" DLLEXPORT void set_DeviceModel(const char16_t* szDeviceModel);
// ---
extern "C" DLLEXPORT const char16_t* get_UserId();
extern "C" DLLEXPORT void set_UserId(const char16_t* szUserId);
// ---
extern "C" DLLEXPORT const char16_t* get_Tags();
extern "C" DLLEXPORT void set_Tags(const char16_t* szlszTags);
// ---
extern "C" DLLEXPORT const char16_t* get_GeoLocation();
extern "C" DLLEXPORT void set_GeoLocation(const char16_t* szdictValue);
// ---
extern "C" DLLEXPORT const char16_t* get_SessionAuthMechanism();
extern "C" DLLEXPORT void set_SessionAuthMechanism(const char16_t* szdictValue);
// --- Environment / Storage functions.
extern "C" DLLEXPORT const char16_t* StorageGetDefaultEntryAsString();
extern "C" DLLEXPORT const char16_t* StorageGetEntryAsString(const char16_t* wszName);
// ---
extern "C" DLLEXPORT uint32_t StorageSetDefaultEntryFromString(const char16_t* wszStorageEntry, const bool bKeepLatest, const char16_t* wszOrigin, const bool bSessionData);
extern "C" DLLEXPORT uint32_t StorageSetEntryFromString(const char16_t* wszName, const char16_t* wszStorageEntry, const bool bKeepLatest, const char16_t* wszOrigin, const bool bSessionData);
// ---
extern "C" DLLEXPORT uint32_t StorageRemoveDefaultEntry();
extern "C" DLLEXPORT uint32_t StorageRemoveEntry(const char16_t* wszName);
extern "C" DLLEXPORT uint32_t StorageRemoveMultipleEntries(const bool bSessionOnly);
// --- Configuration fields.
extern "C" DLLEXPORT const char16_t* get_RestUrl();
extern "C" DLLEXPORT void set_RestUrl(const char16_t* szValue);
// ---
extern "C" DLLEXPORT uint32_t get_SendRetriesOnFailure();
extern "C" DLLEXPORT void set_SendRetriesOnFailure(uint32_t nValue);
// ---
extern "C" DLLEXPORT CSharpTimeSpan get_SendRetryInterval();
extern "C" DLLEXPORT void set_SendRetryInterval(CSharpTimeSpan tsValue);
// ---
extern "C" DLLEXPORT CSharpTimeSpan get_SendNextBatchWait();
extern "C" DLLEXPORT void set_SendNextBatchWait(CSharpTimeSpan tsValue);
// ---
extern "C" DLLEXPORT CSharpTimeSpan get_StragglerTimeout();
extern "C" DLLEXPORT void set_StragglerTimeout(CSharpTimeSpan tsValue);
// ---
extern "C" DLLEXPORT uint32_t get_EventsPerSendAttempt();
extern "C" DLLEXPORT void set_EventsPerSendAttempt(uint32_t nValue);
// ---
extern "C" DLLEXPORT uint32_t get_LogsPerSendAttempt();
extern "C" DLLEXPORT void set_LogsPerSendAttempt(uint32_t nValue);
// ---
extern "C" DLLEXPORT uint32_t get_TelemetryEntriesPerSendAttempt();
extern "C" DLLEXPORT void set_TelemetryEntriesPerSendAttempt(uint32_t nValue);
// ---
extern "C" DLLEXPORT uint32_t get_StorageEntriesPerSendAttempt();
extern "C" DLLEXPORT void set_StorageEntriesPerSendAttempt(uint32_t nValue);
// ---
extern "C" DLLEXPORT CSharpTimeSpan get_PruneSentItemsOlderThan();
extern "C" DLLEXPORT void set_PruneSentItemsOlderThan(CSharpTimeSpan tsValue);
// ---
extern "C" DLLEXPORT uint32_t get_MaximumCachedItems();
extern "C" DLLEXPORT void set_MaximumCachedItems(uint32_t nValue);
// ---
extern "C" DLLEXPORT bool get_RetainLocalAfterSent();
extern "C" DLLEXPORT void set_RetainLocalAfterSent(bool bValue);
// ---
extern "C" DLLEXPORT bool get_ReAuthenticateBeforeTokenExpires();
extern "C" DLLEXPORT void set_ReAuthenticateBeforeTokenExpires(bool bValue);
// ---
extern "C" DLLEXPORT bool get_UseDatabase();
extern "C" DLLEXPORT void set_UseDatabase(bool bValue);
// ---
extern "C" DLLEXPORT const char16_t* get_AppConfigAuthMechanism();
extern "C" DLLEXPORT void set_AppConfigAuthMechanism(const char16_t* szdictValue);
// ---
extern "C" DLLEXPORT bool ReadConfig();
// --- C# callback mechanism.
extern "C" DLLEXPORT bool GetAuthSecretCSharp();
extern "C" DLLEXPORT void SetGetAuthSecretCallbackRet(const char16_t* szAuthSecret);
extern "C" DLLEXPORT void SetServingCSharp(const bool bServingCSharp);
extern "C" DLLEXPORT bool GetNextDiagnosticString(OUT char16_t** pbstrString);
// --- end C# callback mechanism.
// --- Test code.
extern "C" DLLEXPORT CURLCode HTTPGet(const char16_t* bstrUrl, OUT char16_t** pbstrResponse);
extern "C" DLLEXPORT CURLCode HTTPPost(const char16_t* bstrUrl, OUT char16_t** pbstrResponse);
// Easy to call from C++ that links the .dll.
extern "C" DLLEXPORT int iXRLibAnalyticsTests(int argc, char* argv[]);
// Easy to call from C# interop.
extern "C" DLLEXPORT int iXRLibAnalyticsTestsInterop(const char16_t* bstrCommandLine);
extern "C" DLLEXPORT const char16_t* TestGetAuthSecretCallback();
