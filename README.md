# Prerequisites

Make sure your Xcode project is setup to use Base Internationalization. 

Go to your project settings by selecting the project file in the Xcode file explorer. Select the project itself, not one of your targets. Under Localization, check the `Use Base Internationalization` checkbox. 

We recommend you add all of the languages you want your app translated into in the Languages list. However, you will not need to enable localization for every Interface Builder file (Storyboards, XIBs). Strings will be extracted from those and localized at runtime by the Smartling SDK.


In your code, all of your user facing strings need to be externalized using the macro `NSLocalizedString`. This is the standard way of localizing apps on iOS, and Smartling simply overrides its behavior. You can then use Apple's `genstrings` command line tool to extract all strings from your code into a Localizable.strings file.

# Installation instructions

- In your project's `podfile`, add the Smartling pod as shown below. Use `Smartling-framework` if you're using Swift or if you're using CocoaPods' `use_frameworks!` option, or simply `Smartling` otherwise. 
```
source 'https://github.com/CocoaPods/Specs.git'

target 'MyApp' do
	pod 'Smartling'
end

``` 

- In your app's AppDelegate, import the library and call the start method as shown below:
```objc
#import "AppDelegate.h"
#import <Smartling/Smartling.h>

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [Smartling startWithProjectId:@"<ProjectID>" andOptions:@{SLLogging : @(SLLoggingDebug), SLMode: @(SLEdition)}];
    return YES;
}

@end
```

# Options

### SLLogging
Defines the level of logging the SDK outputs to the console. 
* SLLoggingNone (default)
* SLLoggingInfo
* SLLoggingDebug

### SLMode
* SLDisabled (default) - The SDK doesn't affect the app whatsoever
* SLOTAUpdates - Published strings are served to the user in his language and displayed in the app
* SLEdition - Members of your team can log in to edit strings and review them in context inside the app

# Plurals

To localize strings with plural rules, use the `pluralizedStringWithKey:value:` method instead of `NSLocalizedString` as follows:
```objc
NSNumber *value = @(5);
label.text = [NSString stringWithFormat:[Smartling pluralizedStringWithKey:@"<key>" value:value], value];
```
