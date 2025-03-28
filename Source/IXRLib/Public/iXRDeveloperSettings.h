// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AbxrDeveloperSettings.generated.h"

/**
 * 
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Abxr"))
class ABXRLIB_API UAbxrDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	FString appID;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	FString orgID;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	FString authSecret;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	bool headsetTracking;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	int trackingUpdatesPerMinute = 4;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	FString restUrl = "https://libapi.informxr.io/v1/";
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	int sendRetriesOnFailure = 3;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	int sendRetryIntervalSeconds = 3;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	int sendNextBatchWaitSeconds = 30;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	int stragglerTimeoutSeconds = 15;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	int eventsPerSendAttempt = 4;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	int logsPerSendAttempt = 4;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	int telemetryEntriesPerSendAttempt = 4;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	int storageEntriesPerSendAttempt = 4;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	int pruneSentItemsOlderThanHours = 12;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	int maximumCachedItems = 1024;
	
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category="AbxrConfig")
	bool retainLocalAfterSent;

	UFUNCTION(BlueprintCallable, Category="AbxrConfig")
	static const UAbxrDeveloperSettings* GetAbxrConfig();
};
