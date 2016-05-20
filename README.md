# Installation instructions

- In your project's `podfile`, add the Smartling source and pod as shown below:
```
source 'https://github.com/Smartling/ios-lqa-sdk.git'
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
    [Smartling startWithProjectId:@"<ProjectID>" andOptions:@{SLLogging : @(SLLoggingDebug)}];
    return YES;
}

@end
```

# Plurals

To localize strings with plural rules, use the `pluralizedStringWithKey:value:` method instead of `NSLocalizedString` as follows:
```objc
NSNumber *value = @(5);
label.text = [NSString stringWithFormat:[Smartling pluralizedStringWithKey:@"<key>" value:value], value];
```
