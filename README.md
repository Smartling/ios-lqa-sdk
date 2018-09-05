![Bitrise](https://app.bitrise.io/app/b7bd639ab67aa73b/status.svg?token=GQ4cumwRzJP71qY-MO0OXQ&branch=master)
[![CocoaPods](https://img.shields.io/cocoapods/v/SmartlingFramework.svg)](https://github.com/Smartling/ios-lqa-sdk) 
[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)


* [How to use](https://help.smartling.com/docs/mobile-apps)
* [FAQ](https://github.com/Smartling/ios-lqa-sdk/wiki/FAQ)
* [Release Notes](https://github.com/Smartling/ios-lqa-sdk/wiki/Release-Notes)

# Prerequisites

Make sure your Xcode project is setup to use Base Internationalization. 

Go to your project settings by selecting the project file in the Xcode file explorer. Select the project itself, not one of your targets. Under Localization, check the `Use Base Internationalization` checkbox. 

We recommend you add all of the languages you want your app translated into in the Languages list. However, you will not need to enable localization for every Interface Builder file (Storyboards, XIBs). Strings will be extracted from those and localized at runtime by the Smartling SDK.


In your code, all of your user facing strings need to be externalized using the macro `NSLocalizedString`. This is the standard way of localizing apps on iOS, and Smartling simply overrides its behavior.

# Import your strings into Smartling

## Manually

You can upload your project's `.strings` files manually into the Smartling dashboard to make your strings available for your translators. You may use Apple's `genstrings` command line tool to extract all strings from your code into a Localizable.strings file. For localized strings included in Interface Builder files, you can use the `ibtool` command line tool to do so.

## Automatically

Smartling provides a Ruby gem to extract your strings and upload them to the dashboard automatically. Install it using Rubygems with the following command:
```bash
gem install smartling_xcode
```
Then run
```bash
smartling_xcode init
```
You will be prompted to enter your project ID and API key, which you can find on the Smartling dashboard.

In your Xcode project folder, you can now run
```bash
smartling_xcode push
```
Your app's strings are now available on the dashboard.

# Installation instructions

Pick the SDK that suits your needs among the following options:
- **Full Smartling SDK** - The full Smartling SDK features the in-app review, context capture and over-the-air serving modes, and is the most convenient solution for all your localization needs. It is available as a **static library** (suitable for Objective-C apps that target iOS < 8.0) or as a **dynamic framework** (suitable for Swift apps or for Objective-C apps that only target iOS > 8.0). It will typically add about 200Kb to your app on the end user's device.
- **MDN-only static library** - A lighter version of the Smartling SDK that includes only the over-the-air serving mode. This option is recommended for your release builds if you have tight app size requirements. It will typically add about 65Kb to the app on the user's device. It is only available as a static library.

_(App size measurements were made on the iPhone 7 version of a release build of a sample app with bitcode enabled. Results may vary.)_

## Full Smartling SDK

### 1. Install the Smartling package

#### Static library

Choose our static library if your app is in Objective-C and targets iOS < 8.0. In your project's `podfile`, add the Smartling pod as shown below. 
```ruby
source 'https://github.com/CocoaPods/Specs.git'

target 'MyApp' do
	pod 'SmartlingSDK'
end

``` 

#### Dynamic framework

Choose our dynamic framework if one of the following conditions applies to your app:
- The `use_frameworks!` option is already present and uncommented in your podfile.
- Your app contains Swift code.
- Your app doesn't target iOS < 8.0.

In your project's `podfile`, add the Smartling-framework pod as shown below.
```ruby
source 'https://github.com/CocoaPods/Specs.git'

target 'MyApp' do
    use_frameworks!
    pod 'SmartlingFramework'
end

``` 

If you use Carthage, add the SmartlingFramework repository to your `cartfile` as shown below.
```
github "Smartling/ios-lqa-framework"
```

### 2. Initialize the library

#### Objective-C

In your app's main.m, import the library and call the start method as shown below:
```objc
#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import <Smartling/Smartling.h>

int main(int argc, char * argv[]) {
    @autoreleasepool {
        [Smartling startWithProjectId:@"<Project ID>" andOptions:@{SLLogging : SLLoggingInfo, SLMode: <Mode>}];
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
```

#### Swift

In your app's AppDelegate.swift, import the library and call the start method as shown below:
```swift
import UIKit
import Smartling

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    ...

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        Smartling.start(withProjectId: "<Project ID>", andOptions: [SLLogging: SLLoggingInfo, SLMode: <Mode>])
        return true
    }

```

### 3. Check your build settings

Go to your project's build settings and look for `Other linker flags`. Make sure the `-ObjC` flag is present or add it.

## MDN-only library

In your project's `podfile`, add the Smartling pod as shown below. 
```ruby
source 'https://github.com/CocoaPods/Specs.git'

target 'MyApp' do
	pod 'Smartling-MDN'
end

``` 

In your app's main.m, import the library and call the start method as shown below:
```objc
#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import <Smartling-MDN/SmartlingMDN.h>

int main(int argc, char * argv[]) {
    @autoreleasepool {
        [SmartlingMDN startWithProjectId:@"<Project ID>" OTAKey:@"<OTA key>" andOptions:@{SLLogging: SLLoggingInfo}];
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
```

**The OTA key is your project's AES key for OTA updates, it was sent to you by your Smartling contact when enabling mobile in your Smartling account. You will not find this key in your Smartling dashboard.**

Finally, go to your project's build settings and look for `Other linker flags`. Make sure the `-ObjC` flag is present or add it.

# Modes (full Smartling SDK only)

## OTA serving

In OTA serving mode, published strings are served to end users in their language and displayed in the app. [How to use OTA serving](https://help.smartling.com/docs/mobile-delivery-network).


To build the app in OTA serving mode:
* Use `SLMode: SLOTAServing`
* Add the `SLOTAKey` option, with your project's AES key for OTA updates. **The OTA key was sent to you by your Smartling contact when enabling mobile in your Smartling account. You will not find this key in your Smartling dashboard.**

## In App Review

The in-app review mode lets members of your team log in to edit strings and review them in context inside the app. [How to use in-app review](https://help.smartling.com/docs/in-app-review-of-your-ios-app).


To build the app in in-app review mode, use `SLMode: SLInAppReview` in the Smartling start method.

## Context Capture

With the context capture mode, the user can create screenshots interactively when running the app. [How to use context capture](https://help.smartling.com/docs/mobile-context).


To build the app in context capture mode:
* Use `SLMode: SLContextCapture` in the Smartling start method.
* Generate an API v2 token from the Smartling dashboard. Pass the user ID and secret using the options `SLAPIUserId` and `SLAPIUserSecret`.

### Automated Context Capture

You can automate your context capture using Xcode UI tests. 

Your app will need to be launched in context capture mode. Add the following method to your app's UI tests and call it everywhere you need to trigger a screen capture:

```objc
+ (void)triggerContextCapture {
    XCUIApplication *app = [[XCUIApplication alloc] init];
    XCUIElement *window = [app.windows elementBoundByIndex:0];
    XCUICoordinate *origin = [window coordinateWithNormalizedOffset:CGVectorMake(0.0, 0.0)];
    XCUICoordinate *triggerCoord = [origin coordinateWithOffset:CGVectorMake(100, 100)];
    [triggerCoord pressForDuration:5.0];
}
```


You can also trigger screenshots directly from your app's code by calling the following method:
```objc
[Smartling captureWindow:<UIWindow> withCompletion:^(NSError *error) {
    // Error handling
}];
```

You may obtain your app's main window by calling `[[UIApplication sharedApplication] keyWindow]`, or from a View Controller with `self.view.window`.

## In App Review and Context Capture

This mode is identical to the in-app review mode, but an additional option in the actions menu is added to let the users switch to context capture mode from within the app. That way, they can access both modes with one single build of your app.

To build the app in this combined mode, use `SLMode: SLInAppReviewAndContextCapture` in the Smartling start method, and include the API v2 tokens as described in the "Automated Context Capture" section above.

## Disabled

You can leave the Smartling library in your project but disable its function entirely by omitting the start method, or calling it with the `SLMode: SLDisabled` option.

# Additional Options

### SLLogging
Defines the level of logging the SDK outputs to the console. 
* SLLoggingNone (default)
* SLLoggingInfo
* SLLoggingDebug


# Locale change at runtime (full Smartling SDK only)

In OTA serving mode, if you want your users to be able to change their locale from within the app, Smartling helps you achieve this goal very easily.

- Generate an API v2 token from the Smartling dashboard. Pass the user ID and secret using the Smartling start options `SLAPIUserId` and `SLAPIUserSecret`.
- Set the `SLAllowLocaleChange` option to `@YES`. Optionally, you can use the `SLForceLocale` to force a locale on startup, if you're saving the user's choice for example. If you don't set this option, the device locale will be used.
- To show the user a list of available locales, Smartling lets you request the list of locales available to your app project. Call the method `[Smartling getProjectLocalesWithCompletion:^(NSArray *locales, NSError *error){...}]`, and the completion block will give you an array of locales including the locale name and locale ID. 
- When the user has selected a locale, you can set it using the method `[Smartling setLocaleWithId:<NSString *localeId> andCompletion:^(BOOL success){...}]`. The completion block will be called once the UI is entirely updated with texts from the selected locale. 


# Plurals

To localize strings with plural rules, use the `pluralizedStringWithKey:value:` method instead of `NSLocalizedString` as follows:
```objc
NSNumber *value = @(5);
label.text = [NSString stringWithFormat:[Smartling pluralizedStringWithKey:@"<key>" value:value], value];
```


