// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FStringToCharConverter.generated.h"

/**
 * 
 */
UCLASS()
class IXRLIB_API UFStringToCharConverter : public UObject
{
	GENERATED_BODY()

private:
	// Persistent storage for the UTF-16 string
	TArray<char16_t> UTF16Buffer;

	UPROPERTY()
	FString SavedString;
public:
	UFStringToCharConverter() { };
	// Convert FString to a char16_t* safely
	char16_t* Convert(const FString& UnrealString)
	{
		SavedString = UnrealString;
		// Convert FString to a TCHAR* (UTF-16 on most platforms)
		const TCHAR* SourceData = *SavedString;

		// Resize buffer to accommodate the string (plus null-terminator)
		int32 Length = FCString::Strlen(SourceData) + 1; // +1 for null-terminator
		UTF16Buffer.SetNumUninitialized(Length);

		// Copy the data into the TArray
		for (int32 i = 0; i < Length; ++i)
		{
			UTF16Buffer[i] = static_cast<char16_t>(SourceData[i]);
		}

		// Return a pointer to the start of the buffer
		return UTF16Buffer.GetData();
	}
	FString ReverseConvert(const char16_t* String)
	{
		if (String == nullptr)
		{
			return FString(); // Return an empty FString if the input is null
		}

		// Find the length of the null-terminated UTF-16 string
		int32 Length = 0;
		while (String[Length] != '\0')
		{
			++Length;
		}

		// Allocate an FString from the UTF-16 data
		FString Result;
		Result.Reserve(Length); // Pre-allocate memory for better performance

		for (int32 i = 0; i < Length; ++i)
		{
			Result.AppendChar(static_cast<TCHAR>(String[i])); // Convert each char16_t to TCHAR and append
		}

		return Result;
	}
	// Ensure the buffer persists safely while in use
	const TArray<char16_t>& GetBuffer() const
	{
		return UTF16Buffer;
	}
};
