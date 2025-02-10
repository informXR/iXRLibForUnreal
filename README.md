# iXRLib For Unreal Engine

## Installation

To install the plugin, you need to clone the project or download a ZIP of the project from the GitHub repository ([https://github.com/informXR/iXRLibForUnreal](https://github.com/informXR/iXRLibForUnreal)) into the /Plugins folder in your Unreal project folder (create the folder if it doesn’t exist). Important: Your project has to be C++-based.

Here is a list of the Plugins you need to have in your project to make VR workable:
* OpenXR  
* OpenXREyeTracker  
* OpenXRHandTracking
![](https://github.com/informXR/iXRLibForUnreal/blob/main/ReadmeImages/plugins.png?raw=true)

Pay attention to the other VR Plugins, some of them may break the build.

If you use the default VRPawn from the EpicGames VR template you also needed to add InputConfig to the OpenXR Input Section in the Project Settings
![](https://github.com/informXR/iXRLibForUnreal/blob/main/ReadmeImages/template.png?raw=true)

## Configuration

After you install the iXRLib plugin into your plugins folder you should see an additional category “iXR” in Game section in Project Settings.  
![](https://github.com/informXR/iXRLibForUnreal/blob/main/ReadmeImages/project-settings.png?raw=true)

In the “iXR” section, you can configure parameters of the plugin.  
***IMPORTANT: APP ID, ORG ID, and AUTH SECRET need to be filled in.***  
***You can get these parameters from your iXR account, watch here \- [iXR Home](https://app.informxr.io/dashboard/home)***  
![](https://github.com/informXR/iXRLibForUnreal/blob/main/ReadmeImages/config.png?raw=true)
If you need to change the Rest URL you can also change it in the iXR configuration page in the project settings.

## Calling the methods

All the wrapped methods are static and have a UFUNCTION(BlueprintCallable) macro that makes them callable everywhere, either C++ or Blueprints. To call any of the methods, just right-click on the Blueprint graph and type “**iXRLib**”. You will see all available static methods that are wrapped in the C++ class \- “**IXRBlueprintLibrary.h**”.

***Blueprint***  
![](https://github.com/informXR/iXRLibForUnreal/blob/main/ReadmeImages/blueprint.png?raw=true)

***C++***  
UIXRBlueprintLibrary::LogDebugSynchronous\_BFL(MyString)  
