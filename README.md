# Prerequisites

Make sure your Xcode project is setup to use Base Internationalization. 

Go to your project settings by selecting the project file in the Xcode file explorer. Select the project itself, not one of your targets. Under Localization, check the `Use Base Internationalization` checkbox. 

We recommend you add all of the languages you want your app translated into in the Languages list. However, you will not need to enable localization for every Interface Builder file (Storyboards, XIBs). Strings will be extracted from those and localized at runtime by the Smartling SDK.


In your code, all of your user facing strings need to be externalized using the macro `NSLocalizedString`. This is the standard way of localizing apps on iOS, and Smartling simply overrides its behavior.

# Import your strings into Smartling

## Manually

You can upload your project's `.strings` files manually into the Smartling dashboard to make your strings available for your translators. You can then use Apple's `genstrings` command line tool to extract all strings from your code into a Localizable.strings file. For localized strings included in Interface Builder files, you can use the `ibtool` command line tool to do so.

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

In your project's `podfile`, add the Smartling pod as shown below. Use `Smartling-framework` if you're using Swift or if you're using CocoaPods' `use_frameworks!` option, or simply `Smartling` otherwise. 
```ruby
source 'https://github.com/CocoaPods/Specs.git'

target 'MyApp' do
	pod 'Smartling'
end

``` 

In your app's main.m, import the library and call the start method as shown below:
```objc
#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import "Smartling.h"

int main(int argc, char * argv[]) {
    @autoreleasepool {
        [Smartling startWithProjectId:@"<Project ID>" andOptions:@{SLLogging : @(SLLoggingDebug), SLMode: @(SLInAppReview)}];
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
```
For Swift apps you can call this method in your AppDelegate's `application:didFinishLaunchingWithOptions:` method instead.

# Options

### SLLogging
Defines the level of logging the SDK outputs to the console. 
* SLLoggingNone (default)
* SLLoggingInfo
* SLLoggingDebug

### SLMode
* SLDisabled (default) - The SDK doesn't affect the app whatsoever
* SLOTAServing - Published strings are served to the user in his language and displayed in the app
* SLInAppReview - Members of your team can log in to edit strings and review them in context inside the app

### SLOTAKey
Your project's AES key for OTA updates (required for OTA Serving mode)

### SLAPIUserId, SLAPIUserSecret
Smartling API v2 user ID and secret. Required options for OTA Serving mode if the `getProjectLocalesWithCompletion:` method is used.

### SLForceLocale
Set this option to a locale ID in OTA Serving mode to ignore automatic locale detection and force an arbitrary locale.

### SLAllowLocaleChange
Set this option to `@YES` in OTA Serving mode if your app allows the user to change the locale from within the app. Failing to set this option and calling the `setLocaleWithId:andCompletion:` method will result in inconsistent UI language.

# Locale change at runtime

If you want your users to be able to change their locale from within the app, Smartling helps you achieve this goal very easily.

- First, you will need to set the `SLAllowLocaleChange` option to `@YES`. Optionally, you can use the `SLForceLocale` to force a locale on startup, if you're saving the user's choice for example. If you don't set this option, the device locale will be used.
- To show the user a list of available locales, Smartling lets you request the list of locales available to your app project. Call the method `[Smartling getProjectLocalesWithCompletion:^(NSArray *locales, NSError *error){...}]`, and the completion block will give you an array of locales including the locale name and locale ID. 
- When the user has selected a locale, you can set it using the method `[Smartling setLocaleWithId:<NSString *localeId> andCompletion:^(BOOL success){...}]`. The completion block will be called once the UI is entirely updated with texts from the selected locale. 


# Plurals

To localize strings with plural rules, use the `pluralizedStringWithKey:value:` method instead of `NSLocalizedString` as follows:
```objc
NSNumber *value = @(5);
label.text = [NSString stringWithFormat:[Smartling pluralizedStringWithKey:@"<key>" value:value], value];
```
