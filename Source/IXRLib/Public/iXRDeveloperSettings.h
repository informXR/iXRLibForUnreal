// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "iXRDeveloperSettings.generated.h"

/**
 * 
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "iXR"))
class IXRLIB_API UiXRDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	FString appID;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	FString orgID;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	FString authSecret;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	bool headsetTracking;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	int trackingUpdatesPerMinute = 4;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	FString restUrl = "https://libapi.informxr.io/v1/";
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	int sendRetriesOnFailure = 3;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	int sendRetryIntervalSeconds = 3;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	int sendNextBatchWaitSeconds = 30;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	int stragglerTimeoutSeconds = 15;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	int eventsPerSendAttempt = 4;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	int logsPerSendAttempt = 4;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	int telemetryEntriesPerSendAttempt = 4;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	int storageEntriesPerSendAttempt = 4;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	int pruneSentItemsOlderThanHours = 12;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	int maximumCachedItems = 1024;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="iXRConfig")
	bool retainLocalAfterSent;

	UFUNCTION(BlueprintCallable, Category="iXRConfig")
	static const UiXRDeveloperSettings* GetiXRConfig();
};
